#include"header.h"
#include"decleration.h"
loff_t lseek_cdev(struct file *filep,loff_t loff,int seek_pos)
{
	Dev *ldev;
	ldev = filep->private_data;
	#ifdef DEBUG
		printk(KERN_INFO"Start: %s",__func__);
	#endif
	if(loff > ldev->devsize)
	{
		printk(KERN_ERR"offset position is more than datasize: %s",__func__);
		goto OUT;
	}
	switch(seek_pos)
	{
		case 0:
			filep->f_pos = loff; 
			break;
		case 1:
			filep->f_pos += loff;
			break;
		case 2:
			filep->f_pos = (loff_t)ldev->datasize - loff;
			break;
		default:
			printk(KERN_ERR"seek_pos is wrong: %s",__func__);
			goto OUT;

	}
	#ifdef DEBUG
		printk(KERN_INFO"filep->pos: %lld",filep->f_pos);
	#endif
	#ifdef DEBUG
		printk(KERN_INFO"END: %s",__func__);
	#endif
OUT:
	return filep->f_pos;
}
