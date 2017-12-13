#include"header.h"
#include"decleration.h"
size_t write_cdev(struct file *filep,const char __user *buff,size_t size,loff_t *loffp)
{
	size_t noc;
	int tbyte;
	unsigned long ret;
	Dev *ldev;
	Qset *lqset;
	ldev = filep->private_data;
	ldev->first = lqset = create_scull(size);
	noc = 0;
	tbyte = ldev->regsize;
	lsize  = size;
	while(lqset)
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
			if(lsize>0 && lsize<tbyte)
				tbyte = lsize;
			else if(lsize<=0)
				break;
		}
		lqset = lqset->next;
	}
	return noc;
OUT:
	return -1;
}
