#include"header.h"
#include"decleration.h"
int open_cdev(struct inode *inodep,struct file *filep)
{
	Dev *ldev;
	ldev = container_of(inodep->i_cdev,Dev,c_dev);
	if(!ldev)
	{
		#ifdef DEBUG
			printk(KERN_INFO"%s :error container_of()",__func__);
		#endif
		goto OUT;
	}
	filep->private_data = ldev;
	if(!ldev->first)
	{
		#ifdef DEBUG
			printk(KERN_INFO"%s :empty nothing to trim",__func__);
		#endif
	}
	return 0;
OUT:
	return -1;
}
