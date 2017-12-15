#include"header.h"
#include"decleration.h"
ssize_t read_cdev(struct file *filep,char __user *buff,size_t size,loff_t *loffp)
{
	size_t lsize,ret,fsize;
	Qset *lqset;
	Dev *ldev;
	int j,i,k,noi;
	#ifdef DEBUG
		printk(KERN_INFO"Begin: %s",__func__);
	#endif
	j=i=k=0;
	ldev = NULL;
	lsize = size;
	ldev = filep->private_data;
	if(!ldev)
	{
		#ifdef DEBUG
			printk(KERN_INFO"filep->private_data fail");
			goto out;
		#endif
	}
	if(lsize > (ldev->datasize))
		lsize = ldev->datasize;
	lqset = ldev->first;
	fsize = ldev->regsize;
	noi = lsize /((ldev->noreg)*(ldev->regsize));
	if(lsize %((ldev->noreg)*(ldev->regsize)))
		noi++;
	while(lsize)
	{
		ret = __copy_to_user(buff+i,lqset->data[j],fsize);
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

	}
	#ifdef DEBUG
		printk(KERN_INFO"End: %s",__func__);
	#endif
	return i;
out:
	return -1;
}
