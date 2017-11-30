#include"header.h"
static int m;
module_param(m,int,S_IRUGO);
static int __init func(void)
{
	printk(KERN_INFO"Hello Kernel! Lets gets started\n");
	printk(KERN_INFO"Number send %d\n",m);
	return 0;
}
module_init(func);
