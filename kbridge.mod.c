#include <linux/module.h>
#include <linux/export-internal.h>
#include <linux/compiler.h>

MODULE_INFO(name, KBUILD_MODNAME);

__visible struct module __this_module
__section(".gnu.linkonce.this_module") = {
	.name = KBUILD_MODNAME,
	.init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
	.exit = cleanup_module,
#endif
	.arch = MODULE_ARCH_INIT,
};



static const struct modversion_info ____versions[]
__used __section("__versions") = {
	{ 0x9f222e1e, "alloc_chrdev_region" },
	{ 0xa61fd7aa, "__check_object_size" },
	{ 0xc2f71d5e, "proc_create" },
	{ 0x40a621c5, "snprintf" },
	{ 0xc61793cb, "class_destroy" },
	{ 0xe8213e80, "_printk" },
	{ 0xd272d446, "__stack_chk_fail" },
	{ 0xaa47b76e, "__arch_copy_to_user" },
	{ 0xf64ac983, "__copy_overflow" },
	{ 0x81fb4dda, "cdev_add" },
	{ 0x4f33a1e6, "device_create" },
	{ 0x5ecd0c7c, "class_create" },
	{ 0x7057d579, "mutex_lock_interruptible" },
	{ 0xe54e0a6b, "__fortify_panic" },
	{ 0x0e9cab28, "memset" },
	{ 0x5aec4bc0, "proc_remove" },
	{ 0x0bc5fb0d, "unregister_chrdev_region" },
	{ 0x9aa6980d, "mutex_unlock" },
	{ 0x01d5fe91, "device_destroy" },
	{ 0x5cb46e6d, "validate_usercopy_range" },
	{ 0xaa47b76e, "__arch_copy_from_user" },
	{ 0x9c4ed43a, "alt_cb_patch_nops" },
	{ 0x437e81c7, "simple_read_from_buffer" },
	{ 0xa182729b, "cdev_init" },
	{ 0xbadd58e7, "cdev_del" },
	{ 0xc7ea9460, "module_layout" },
};

static const u32 ____version_ext_crcs[]
__used __section("__version_ext_crcs") = {
	0x9f222e1e,
	0xa61fd7aa,
	0xc2f71d5e,
	0x40a621c5,
	0xc61793cb,
	0xe8213e80,
	0xd272d446,
	0xaa47b76e,
	0xf64ac983,
	0x81fb4dda,
	0x4f33a1e6,
	0x5ecd0c7c,
	0x7057d579,
	0xe54e0a6b,
	0x0e9cab28,
	0x5aec4bc0,
	0x0bc5fb0d,
	0x9aa6980d,
	0x01d5fe91,
	0x5cb46e6d,
	0xaa47b76e,
	0x9c4ed43a,
	0x437e81c7,
	0xa182729b,
	0xbadd58e7,
	0xc7ea9460,
};
static const char ____version_ext_names[]
__used __section("__version_ext_names") =
	"alloc_chrdev_region\0"
	"__check_object_size\0"
	"proc_create\0"
	"snprintf\0"
	"class_destroy\0"
	"_printk\0"
	"__stack_chk_fail\0"
	"__arch_copy_to_user\0"
	"__copy_overflow\0"
	"cdev_add\0"
	"device_create\0"
	"class_create\0"
	"mutex_lock_interruptible\0"
	"__fortify_panic\0"
	"memset\0"
	"proc_remove\0"
	"unregister_chrdev_region\0"
	"mutex_unlock\0"
	"device_destroy\0"
	"validate_usercopy_range\0"
	"__arch_copy_from_user\0"
	"alt_cb_patch_nops\0"
	"simple_read_from_buffer\0"
	"cdev_init\0"
	"cdev_del\0"
	"module_layout\0"
;

MODULE_INFO(depends, "");


MODULE_INFO(srcversion, "0C072EBD86860172C1596D4");
