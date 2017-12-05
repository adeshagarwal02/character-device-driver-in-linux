#include"header.h"
#include"decleration.h"
static void __exit clear(void)
{
	unregister_chrdev_region(dev,nod);
	printk(KERN_INFO"Bye Kernel\n");
}
module_exit(clear);
