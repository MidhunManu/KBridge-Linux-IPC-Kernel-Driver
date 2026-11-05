#ifndef PROC_H
#define PROC_H

#include <linux/proc_fs.h>

#define PROC_PAGE_SIZE 500

unsigned int read_count;
unsigned int write_count;
struct proc_dir_entry* proc_file_entry;

static ssize_t dev_proc_read(struct file* file, char __user *buffer, size_t count, loff_t *offset)
{
	char output[PROC_PAGE_SIZE];
	int len = snprintf(output, sizeof(output), "Read: %u\nWrite %u\n", read_count, write_count);
	return simple_read_from_buffer(buffer, count, offset, output, len);
}

static struct proc_ops dev_proc_ops = {
	.proc_read = dev_proc_read,
};

#endif
