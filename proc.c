// SPDX-License-Identifier: GPL-3.0
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#include "proc.h"

atomic_t read_count = ATOMIC_INIT(0);
atomic_t write_count = ATOMIC_INIT(0);
struct proc_dir_entry *proc_file_entry;

static ssize_t dev_proc_read(struct file *file, char __user *buffer,
			     size_t count, loff_t *offset)
{
	char output[PROC_PAGE_SIZE];
	int len = scnprintf(output, sizeof(output), "Read: %d\nWrite: %d\n",
			    atomic_read(&read_count), atomic_read(&write_count));

	return simple_read_from_buffer(buffer, count, offset, output, len);
}

const struct proc_ops dev_proc_ops = {
	.proc_read = dev_proc_read,
	.proc_lseek = default_llseek,
};

