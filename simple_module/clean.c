#include"header.h"
static void __exit clean(void)
{
	printk(KERN_INFO"Bye Kernel\n");
}
module_exit(clean);
