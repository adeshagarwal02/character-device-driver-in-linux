#include"header.h"
#include"decleration.h"
void close_user(int fd)
{
	close(fd);
	printf("\t\tDevice is closed\n");
}
