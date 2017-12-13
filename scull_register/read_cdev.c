#include"header.h"
#include"decleration.h"
ssize_t read_cdev(struct file *filep,char __user *buff,size_t size,loff_t *loffp)
{
	size_t lsize;
	Qset *lqset;
	Dev *ldev;
	#ifdef DEBUG
		printk(KERN_INFO"Begin: %s",__func__);
	#endif
	lsize = size;
	if(lsize > datasize)
		lsize = datasize;
	ldev = filep->private_data;
	lqset = ldev->first;
	#ifdef DEBUG
		printk(KERN_INFO"End: %s",__func__);
	#endif
	return lsize;
}
