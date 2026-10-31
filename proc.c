#include "proc.h"

struct proc_dir_entry* proc_file_entry;

ssize_t dev_proc_read(struct file* file, char __user *buffer, size_t count, loff_t *offset)
{
	char output[PROC_PAGE_SIZE];
	int len = snprintf(output, sizeof(output), "Read: %u\nWrite %u\n", atomic_read(&read_count), atomic_read(&write_count));
	return simple_read_from_buffer(buffer, count, offset, output, len);
}

struct proc_ops dev_proc_ops = {
	.proc_read = dev_proc_read,
};

