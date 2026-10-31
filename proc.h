#ifndef PROC_H
#define PROC_H

#include <linux/proc_fs.h>

#define PROC_PAGE_SIZE 500

extern unsigned int read_count;
extern unsigned int write_count;
extern struct proc_dir_entry* proc_file_entry;

ssize_t dev_proc_read(struct file* file, char __user *buffer, size_t count, loff_t *offset);

extern struct proc_ops dev_proc_ops;

#endif

