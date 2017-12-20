#include"header.h"
#include"decleration.h"
ssize_t read_cdev(struct file *filep,char __user *buff,size_t size,loff_t *loffp)
{
	size_t lsize,ret,fsize;
	Qset *lqset;
	Dev *ldev;
	int j,i,k,noi,count,rem;
	#ifdef DEBUG
		printk(KERN_INFO"Begin: %s",__func__);
	#endif
	j=i=k=0;
	ldev = NULL;
	if(size > (ldev->devsize))
		size = ldev->devsize;
	lsize = size;
	if(lsize > (ldev->datasize))
		lsize = ldev->datasize;
	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
			printk(KERN_INFO"filep->private_data fail");
			goto out;
		#endif
	}
	lqset = ldev->first;
	noi = lsize /((ldev->noreg)*(ldev->regsize));
	if(lsize %((ldev->noreg)*(ldev->regsize)))
		noi++;
	count = filep->f_pos/((ldev->noreg)*(ldev->regsize));
	while(count)
	{
		lqset = lqset->next;
		count--;
	}
	lsize =lsize - filep->f_pos;
	#ifdef DEBUG
		printk(KERN_INFO"lsize: %ld",lsize);
	#endif
	fsize = ldev->regsize;
	rem = filep->f_pos %((ldev->noreg)*(ldev->regsize));
	j = rem/(ldev->regsize);
	k = j%(ldev->regsize);
	#ifdef DEBUG
		printk(KERN_INFO"filep->f_pos: %lld",filep->f_pos);
	#endif
	
	while(lsize)
	{
		ret = __copy_to_user(buff+i,lqset->data[j]+k,fsize-k);
		printk(KERN_INFO"copy_to: %ld",fsize-k);
		if(ret)
		{
			#ifdef DEBUG
				printk(KERN_INFO"Partial read: %s",__func__);
				goto out;
			#endif
		}
		i += fsize - ret; 
		lsize -= fsize - ret;
		if(j == (ldev->noreg)-1)
		{		
			lqset=lqset->next;
			j = 0;
		}
		else
			j++;
		if((lsize<fsize)&&(lsize>0))
		{
			fsize = lsize;
		}
		else if(lsize < 0)
			lsize = 0;
		k = 0;

	}
	#ifdef DEBUG
		printk(KERN_INFO"End: %s",__func__);
	#endif
	return i;
out:
	return -1;
}
