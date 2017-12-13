INSTALL_DIR=modules
ifneq (${KERNELRELEASE},)
    obj-m :=Adesh.o

Adesh-objs := init.o clean.o open_cdev.o release_cdev.o write_cdev.o read_cdev.o create_scull.o
else
    KERNELDIR ?= /lib/modules/$(shell uname -r)/build
    PWD := $(shell pwd)
default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
	@rm -rf ${INSTALL_DIR}
	@mkdir ${INSTALL_DIR}
	@mv -f *.o *.ko *.mod.c .*.cmd ${INSTALL_DIR}
clean:
	rm -rf ${INSTALL_DIR}
endif
