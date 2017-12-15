#include"header.h"
#include"decleration.h"
int lseek_user(int fd)
{
	int pos;
	int loc,offset;
	printf("\t\t0.For Begnning\n");
	printf("\t\t1.For current\n");
	printf("\t\t2.For end\n");
	printf("\tPlease enter your choice:");
	scanf("%d",&loc);
	printf("\tPlease enter offset:");
	scanf("%d",&offset);
	pos = lseek(fd,offset,loc);
	return pos;
}

