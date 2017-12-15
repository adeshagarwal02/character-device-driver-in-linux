#include"header.h"
#include"decleration.h"
int main()
{
	int choice;
	char o_cdev;
	int wfd=-1,rfd=-1;
	while(1)
	{
		choice = main_menu();
		switch (choice)
		{
			case 1:
				printf("\ta.__open_write__\n");
				printf("\tb.__open_read__\n");
				printf("\tz.__Back__\n");
				scanf(" %c",&o_cdev);
				switch(o_cdev)
				{
					case 'a':
						wfd = open("cdev_A21988",O_WRONLY);
						break;
					case 'b':
						rfd = open("cdev_A21988",O_RDONLY);
						break;
					case 'z':
						printf("\t\tBack to main menu\n");
						break;
					default:
						printf("Bad choice\n");
				}
				break;
			case 2:
				if(wfd == -1)
					printf("Device is not opened to write\n");
				else 
					printf("cherecter successfuly writen %d\n",write_user(wfd));
				break;
			case 3:
				if(rfd == -1)
					printf("Device is not opened to read\n");
				else 
					printf("cherecter successfuly read %d\n",read_user(rfd));
				break;
			case 4:
				if(wfd != -1)
					close_user(wfd);
				if(rfd != -1)
					close_user(rfd);
				break;
			case 5:
				if(rfd != -1)
					printf("Now the position is %d\n",lseek_user(rfd));
				break;
			case 0:
				printf("\t\t__Application_closed__\n");
				exit(EXIT_SUCCESS);
				break;
			default:
				printf("\t\t__wrong choice try again__\n");

		}
	}
		return 0;
}
