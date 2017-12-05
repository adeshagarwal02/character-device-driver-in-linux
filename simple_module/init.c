#include"header.h"
static int m=1;
static char *h = "Adesh Agarwal";
module_param(m,int,S_IRUGO);
module_param(h,charp,S_IRUGO);
static int __init func(void)
{
	printk(KERN_INFO"Hello Kernel! Lets gets started\n");
	printk(KERN_INFO"Number send %d\n",m);
	printk(KERN_INFO"You want to say %s\n",h);
	printk(KERN_INFO"The process is %s,pid is %d\n",current->comm,current->pid);
	return 0;
}
module_init(func);
