#! /bin/bash
Apps.o: app.o write_user.o read_user.o close_user.o main_menu.o lseek_user.o
	gcc -o Apps app.o write_user.o read_user.o close_user.o main_menu.o lseek_user.o

app.o: app.c header.h decleration.h
	gcc -c app.c

write_user.o: write_user.c header.h decleration.h
	gcc -c write_user.c

read_user.o: read_user.c header.h decleration.h
	gcc -c read_user.c

close_user.o: close_user.c header.h decleration.h
	gcc -c close_user.c

main_menu.o: main_menu.c header.h decleration.h
	gcc -c main_menu.c

lseek_user.o: lseek_user.c header.h decleration.h
	gcc -c lseek_user.c

clean:
	rm -rf *.o
