#include"header.h"
#include"decleration.h"
#include"fops.h"
unsigned int majorno = MAJORNO;
static int __init func(void)
{
	printk(KERN_INFO"Regstring device\n");
	register_chrdev(majorno,DEVNAME,&fops);
	return 0;
}
module_init(func);
