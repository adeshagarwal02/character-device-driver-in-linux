#include"header.h"
#include"decleration.h"
static void __exit clean(void)
{
	printk(KERN_INFO"Bye kernel\n");
	unregister_chrdev(majorno,DEVNAME);
}
module_exit(clean);
