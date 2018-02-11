obj-m := HelloWorld.o Template.o eachprocess.o listprocess.o timeval.o 

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) modules
clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(shell pwd) clean
