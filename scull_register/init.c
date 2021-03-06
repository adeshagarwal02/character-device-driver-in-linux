#include"header.h"
#include"decleration.h"
#include"fops.h"
unsigned int majorno = MAJORNO;
unsigned int minorno = MINORNO;
unsigned int nod = NOD;
int noreg = NOREG;
int devsize = DEVSIZE;
int regsize = REGSIZE;
int datasize = DATASIZE;
dev_t dev,devno;
Dev *device;
static int __init func(void)
{
	int ret;
	int i;
	printk(KERN_INFO"Hello Kernel\n");
	if(majorno)
	{
		ret = register_chrdev_region(minorno,nod,DEVNAME);
		#ifdef DEBUG
			printk(KERN_INFO"Inside register_cherdev_region");
		#endif	
		if(ret == -1)
		{
			printk(KERN_INFO"register_chrdev_region()\n");
			goto OUT;
		}
		
	}
	else
	{
		ret = alloc_chrdev_region(&dev,minorno,nod,DEVNAME);
		#ifdef DEBUG
			printk(KERN_INFO"Inside alloc_chrdev_region");
		#endif	
		if(ret == -1)
		{
			printk(KERN_INFO"error:alloc_chrdev_region()\n");
			goto OUT;
		}
	}
	majorno = MAJOR(dev);
//	minorno = MINOR(dev);
	device = (Dev *)kmalloc(sizeof(Dev)*nod,GFP_KERNEL);
	memset(device,'\0',sizeof(Dev)*nod);
	printk(KERN_INFO"Device no: %d",dev);
	printk(KERN_INFO"Major no: %d",majorno);
	for(i=0;i<nod;i++)
	{
		device[i].regsize = regsize;
		device[i].noreg = noreg;
		device[i].devsize = devsize;
		device[i].datasize = datasize;
		cdev_init(&device[i].c_dev,&fops);
		devno = MKDEV(majorno,i);
		ret = cdev_add(&device[i].c_dev,devno,1);
		if(ret == -1)
		{
			#ifdef DEBUG
				printk(KERN_INFO"error:cdev_add()failed");
			#endif	
			goto unregister;

		}
		#ifdef DEBUG
			printk(KERN_INFO"Minor no: %d\n",i);
		#endif	
	}
	return 0;
unregister:
	unregister_chrdev_region(dev,nod);
OUT:
	return -1;
}
module_init(func);
