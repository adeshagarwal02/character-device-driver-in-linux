#include"header.h"
#include"decleration.h"
int write_user(int wfd)
{
	int lwrote;
	char *buff ="Hello adesh you successfuly write and read to the device from the user space";
	lwrote  = write(wfd,buff,strlen(buff));
	return lwrote;
}
