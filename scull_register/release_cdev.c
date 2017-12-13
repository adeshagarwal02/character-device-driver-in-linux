#include"header.h"
#include"decleration.h"
int release_cdev(struct inode *inodep,struct file *filep)
{
	printk(KERN_INFO"Closed function begins: %s",__func__);
	printk(KERN_INFO"Closed function ends: %s",__func__);
	return 0;
}
