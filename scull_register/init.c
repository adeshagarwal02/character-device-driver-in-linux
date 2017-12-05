#include"header.h"
#include"decleration.h"
unsigned int majorno = MAJORNO;
unsigned int minorno = MINORNO;
unsigned int nod = NOD;
dev_t dev;
static int __init func(void)
{
	int ret;
	printk(KERN_INFO"Hello Kernel\n");
	ret = alloc_chrdev_region(&dev,minorno,nod,DEVNAME);
	if(ret == -1)
	{
		printk(KERN_INFO"alloc_chrdev_region()\n");
		goto OUT;
	}
	majorno = MAJOR(dev);
	printk(KERN_INFO"major no = %d\n",majorno);
	return 0;
OUT:
	return -1;
}
module_init(func);
