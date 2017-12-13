#include"header.h"
#include"decleration.h"
Qset *create_scull(size_t size)
{
	Qset *lqset,*fqset;
	int noi,i,j,noq,cnoq;
	size_t lsize,rsize,qsize;
	lsize = size;
	if(lsize > devsize)
		lsize = devsize;
	noi = lsize/(noreg*regsize);
	noi += lsize %(noreg *regsize);
	lqset = fqset = NULL;
	for(i=0;i<noi;i++)
	{
		if(i == 0)
		{
			fqset = lqset = (Qset *)kmalloc(sizeof(Qset),GFP_KERNEL);
			if(!lqset)
			{
				#ifdef DEBUG
					printk(KERN_INFO"kmalloc()fails");
				#endif
			}
			memset(lqset,'\0',sizeof(Qset));
		}
		else
		{
			lqset->next = (Qset *)kmalloc(sizeof(Qset),GFP_KERNEL);
			memset(lqset->next,'\0',sizeof(Qset));
			lqset = lqset->next;
		}
	}
	lqset = fqset;
	qsize = noreg;
	rsize = regsize;
	noq = lsize/(regsize);
	noq += lsize%regsize;
	cnoq = noq;
	for(i = 0;i<noi;i++)
	{
		if(cnoq<qsize)
			qsize = cnoq;
		lqset->data = (void **)kmalloc(sizeof(char *)*qsize,GFP_KERNEL);
		if(!lqset->data)
		{
			#ifdef DEBUG
				printk(KERN_INFO"kmalloc(data)fails");
			#endif
		}
		memset(lqset->data,'\0',sizeof(char*)*qsize);
		cnoq = cnoq - qsize;
		for(j=0;j<qsize;j++)
		{
			if(lsize<rsize)
				rsize = lsize;
			lqset->data[j] = (char *)kmalloc(sizeof(char)*rsize,GFP_KERNEL);
			#ifdef DEBUG
				printk(KERN_INFO"kmalloc(data[%d]",j);
			#endif
			memset(lqset->data[j],'\0',sizeof(char)*rsize);
			lsize = lsize - rsize;
		}
		lqset = lqset->next;
	}
	return fqset;
}
