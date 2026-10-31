// SPDX-License-Identifier: GPL-3.0

/*
 * Copyright (C) 2026 Midhun Manu
 * An Inter Process Communication driver which enables processes in userspace to exchange information with each other.
 */

#include <linux/init.h>
#include <linux/module.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/device.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>

#include "proc.h"

#define DEVICE_NAME "KBRIDGE"
#define DEVICE_BUFFER_SIZE 1024

static dev_t device_no;
static struct cdev char_dev;
static struct class* device_class;
static struct device* char_device;
static DEFINE_MUTEX(buffer_mtx);
static char device_buffer[DEVICE_BUFFER_SIZE];

static int kbridge_open(struct inode *inode, struct file *file)
{
#ifdef DEBUG
    pr_info("kbridge driver opened\n"); 
#endif
    return 0;
}

static int kbridge_release(struct inode *inode, struct file *file)
{
#ifdef DEBUG
    pr_info("kbridge driver closed\n");
#endif
    return 0;
}

static ssize_t kbridge_read(struct file *file, char __user *buffer, size_t length, loff_t *offset)
{
    if (device_buffer[0] == '\0')
        return -EAGAIN;

    if (mutex_lock_interruptible(&buffer_mtx))
        return -ERESTARTSYS;

#ifdef DEBUG
    pr_info("kbridge read invoked\n");
#endif

    size_t message_len = sizeof(device_buffer) - 1;
    size_t remaning;
    size_t bytes_to_copy;

    if (*offset < 0)
        return -EINVAL;

    if (*offset >= message_len)
        return 0;

    remaning = message_len - (size_t)* offset;
    bytes_to_copy = min(length, remaning);

    if (copy_to_user(buffer, device_buffer + *offset, bytes_to_copy))
        return -EFAULT;

    *offset += bytes_to_copy;
    mutex_unlock(&buffer_mtx);
	atomic_inc(&read_count);

    return bytes_to_copy;
}

static ssize_t kbridge_write(struct file* file, const char __user *buffer, size_t length, loff_t *offset)
{
    if (mutex_lock_interruptible(&buffer_mtx))
        return -ERESTARTSYS;

    size_t bytes_to_copy;
    if (*offset < 0 || *offset >= length)
        return -ENOSPC;

#ifdef DEBUG
    pr_info("write invoked");
#endif

    bytes_to_copy = min(length, DEVICE_BUFFER_SIZE - (size_t) *offset);
    if (copy_from_user(device_buffer + (size_t) *offset, buffer, bytes_to_copy))
        return -EFAULT;

    *offset += bytes_to_copy;
    mutex_unlock(&buffer_mtx);
	atomic_inc(&write_count);

    return bytes_to_copy;
}

static const struct file_operations fops = {
    .owner  = THIS_MODULE,
    .open   = kbridge_open,
    .read   = kbridge_read,
    .write  = kbridge_write,
    .release= kbridge_release,
};

static int __init mod_init(void)
{
#ifdef DEBUG
    pr_info("module init");
#endif

    int ret;
    ret = alloc_chrdev_region(&device_no, 0, 1, DEVICE_NAME);
    if (ret)
        return ret;

    device_class = class_create(DEVICE_NAME);
    if (IS_ERR(device_class))
    {
        return PTR_ERR(device_class);
        goto err_unregister;
    }

    cdev_init(&char_dev, &fops);
    char_dev.owner = THIS_MODULE;

    ret = cdev_add(&char_dev, device_no, 1);
    if (ret)
        goto err_class;

    char_device = device_create(device_class, NULL, device_no, NULL, DEVICE_NAME);
    if (IS_ERR(char_device))
    {
        ret = PTR_ERR(char_device);
        goto err_cdev;
    }

	proc_file_entry = proc_create(DEVICE_NAME, 0444, NULL, &dev_proc_ops);
	
	pr_info("proc file created\n");
    pr_info("device registered with major: %d and minor: %d\n", MAJOR(device_no), MINOR(device_no));

    return 0;

err_cdev:
    cdev_del(&char_dev);
err_class:
    class_destroy(device_class);
err_unregister:
    unregister_chrdev_region(device_no, 1);

    return ret;
}

static void __exit mod_exit(void)
{
#ifdef DEBUG
    pr_info("module exit");
#endif

    device_destroy(device_class, device_no);
    cdev_del(&char_dev);
    class_destroy(device_class);
    unregister_chrdev_region(device_no, 1);
	proc_remove(proc_file_entry);
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MidhunManu");
MODULE_DESCRIPTION("An Inter Process Communication driver which enables processes in userspace to exchange information with each other.");

