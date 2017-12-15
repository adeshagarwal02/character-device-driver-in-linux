#include"header.h"
#include"decleration.h"
int release_cdev(struct inode *inodep,struct file *filep)
{
	printk(KERN_INFO"Begins: %s",__func__);
	printk(KERN_INFO"Ends: %s",__func__);
	return 0;
}
