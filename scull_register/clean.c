#include"header.h"
#include"decleration.h"
static void __exit clear(void)
{
	int i;
	for(i=0;i<nod;i++)
	{
		cdev_del(&device[i].c_dev);
	}
	unregister_chrdev_region(dev,nod);
	kfree(device);
	printk(KERN_INFO"Bye Kernel\n");
}
module_exit(clear);
