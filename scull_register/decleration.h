#ifndef MAJORNO
#define MAJORNO 0
#endif

#ifndef MINORNO
#define MINORNO 0
#endif

#ifndef NOD
#define NOD 5
#endif

#ifndef DEVNAME
#define DEVNAME "A21988"
#endif

#ifndef NOREG
#define NOREG 8
#endif 

#ifndef REGSIZE
#define REGSIZE 4
#endif

#ifndef DEVSIZE
#define DEVSIZE 1024
#endif 

#ifndef DATASIZE
#define DATASIZE 0
#endif 

#define DEBUG 0

typedef struct Qset
{
	struct Qset *next;
	void **data;

}Qset;
typedef struct Dev
{
	struct Qset *first;
	struct cdev c_dev;
	int noreg;
	int regsize;
	int devsize;
	int datasize;
}Dev;

extern unsigned int majorno;
extern unsigned int minorno;
extern unsigned int nod;
extern dev_t dev;
extern Dev *device;
extern int noreg,regsize,devsize,datasize;

/*------------------------------------struct file_operations--------------------------------------*/

int open_cdev(struct inode*,struct file *);
ssize_t write_cdev(struct file *,const char __user *,size_t,loff_t *);
ssize_t read_cdev(struct file *,char __user *,size_t,loff_t *);
int release_cdev(struct inode*,struct file *);

/*------------------------------------Additional functions----------------------------------------*/

Qset *create_scull(size_t);

