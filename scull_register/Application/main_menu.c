#include"header.h"
#include"decleration.h"
int main_menu(void)
{
	int choice;
	printf("\t\t____Main_Manu____\n");
	printf("\t\t1.__Open_device__\n");
	printf("\t\t2.__Write_device__\n");
	printf("\t\t3.__read_device__\n");
	printf("\t\t4.__close_device__\n");
	printf("\t\t5.__lseek_device__\n");
	printf("\t\t0.__Exit_application__\n");
	printf("\tPlease enter your choice:");
	scanf("%d",&choice);
	return choice;

}
