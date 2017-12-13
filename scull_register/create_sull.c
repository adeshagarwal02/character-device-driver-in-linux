#include"header.h"
#include"decleration.h"
Qset *create_scull(size_t size)
{
	Qset *lqset,*fqset;
	int noi,i,j;
	size_t lsize;
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
			fqset = lqset = (Qset *)kmalloc(sizeof(Qset),GPF_KERNEL);

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
			lqset = lqset->next = (Qset *)kmalloc(sizeof(Qset),GPF_KERNEL);
			memset(lqset->next,'\0',sizeof(Qset));
		}
	}
	lqset = fqset;
	for(i = 0;i<noi;i++)
	{
		qset->data = (char **)kmalloc(sizeof(char *)*noreg);
		if(!qset->data)
		{
			#ifdef DEBUG
				printk(KERN_INFO"kmalloc(data)fails");
			#endif
		}
		memset(lqset->data,'\0',sizeof(char*)*noreg);
		for(j=0;j<noreg;j++)
		{
			lqset->data[j] = (char *)kmalloc(sizeof(char)*regsize);
			#ifdef DEBUG
				printk(KERN_INFO"kmalloc(data[%d]",j);
			#endif
			memset(lqset->data[j],'\0',sizeof(char)*regsize);
		}
	}
	return fqset;
}
