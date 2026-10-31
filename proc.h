/* SPDX-License-Identifier: GPL-3.0 */
#ifndef PROC_H
#define PROC_H

#include <linux/proc_fs.h>
#include <linux/atomic.h>

#define PROC_PAGE_SIZE 128

extern atomic_t read_count;
extern atomic_t write_count;
extern struct proc_dir_entry *proc_file_entry;
extern const struct proc_ops dev_proc_ops;

#endif

