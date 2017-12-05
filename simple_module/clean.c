#include"header.h"
static void __exit clean(void)
{
	printk(KERN_INFO"Bye Kernel\n");
	printk(KERN_INFO"The process is %s, pid is %d\n",current->comm,current->pid);
}
module_exit(clean);
