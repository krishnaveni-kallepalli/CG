obj-m += hello.o

KDIR = /lib/modules/$(shell uname -r)/build
UDIR=   /mnt/c/Users/KALLKRIS/WSL2-Linux-Kernel-linux-msft-wsl-5.10.y


all:
	make -C $(KDIR)  M=$(UDIR) modules

clean:
	make -C $(KDIR)  M=$(UDIR) cleani
