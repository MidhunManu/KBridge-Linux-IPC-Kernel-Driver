// SPDX-License-Identifier: GPL-3.0

/*
 * Copyright (C) 2026 Midhun Manu
 * An Inter Process Communication driver which enables processes in userspace to exchange information with each other.
 */

#include <linux/init.h>
#include <linux/module.h>

static int __init mod_init(void)
{

#ifdef DEBUG
    pr_info("module init");
#endif
    return 0;
}

static void __exit mod_exit(void)
{
#ifdef DEBUG
    pr_info("module exit");
#endif
}

module_init(mod_init);
module_exit(mod_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("MidhunManu");
MODULE_DESCRIPTION("An Inter Process Communication driver which enables processes in userspace to exchange information with each other.");

