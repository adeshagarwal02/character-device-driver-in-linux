#include"header.h"
#include"decleration.h"
int read_user(int rfd)
{
	int lread;
	char buff[1024];
	lread  = read(rfd,buff,1024);
	printf("%s\n",buff);
	return lread;
}
