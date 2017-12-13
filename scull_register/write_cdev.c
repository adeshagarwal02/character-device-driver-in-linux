#include"header.h"
#include"decleration.h"
ssize_t write_cdev(struct file *filep,const char __user *buff,size_t size,loff_t *loffp)
{
	size_t noc,lsize;
	int tbyte,i;
	unsigned long ret;
	Dev *ldev;
	Qset *lqset;
	#ifdef DEBUG
		printk(KERN_INFO"Begin: %s",__func__);
	#endif
	ldev = filep->private_data;
	ldev->first = lqset = create_scull(size);
	noc = 0;
	tbyte = ldev->regsize;
	lsize  = size;
	while(lsize)
	{
		for(i=0;i<(ldev->noreg);i++)
		{
			ret = __copy_from_user(lqset->data[i],buff+noc,tbyte);
			if(ret == -1)
			{
				#ifdef DEBUG
					printk(KERN_INFO"%s: error copy_from_user()",__func__);
				#endif
				goto OUT;
			}
			else if(ret)
			{
				#ifdef DEBUG
					printk(KERN_INFO"%s:Partial write copy_from_user()",__func__);
				#endif

			}
			noc += tbyte -ret;
			lsize -= tbyte-ret;
			#ifdef DEBUG
				printk(KERN_INFO"lsize: %d",lsize);
			#endif
			if(lsize>0 && lsize<tbyte)
				tbyte = lsize;
			else if(lsize<=0)
				break;
		}
		lqset = lqset->next;
	}
	#ifdef DEBUG
		printk(KERN_INFO"END: %s",__func__);
	#endif
	return noc;
OUT:
	return -1;
}
