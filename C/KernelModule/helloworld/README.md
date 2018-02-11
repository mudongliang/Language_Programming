# Execution

## Module Compilation
```
[mdl@mdl helloworld]$ make 
make -C /lib/modules/4.2.2-1-ARCH/build M=/home/mdl/Repos/Github/CLanguageReview/helloworld modules
make[1]: Entering directory '/usr/lib/modules/4.2.2-1-ARCH/build'
  CC [M]  /home/mdl/Repos/Github/CLanguageReview/helloworld/HelloWorld.o
  Building modules, stage 2.
  MODPOST 1 modules
  CC      /home/mdl/Repos/Github/CLanguageReview/helloworld/HelloWorld.mod.o
  LD [M]  /home/mdl/Repos/Github/CLanguageReview/helloworld/HelloWorld.ko
make[1]: Leaving directory '/usr/lib/modules/4.2.2-1-ARCH/build'
```
## Module Cleanup
```
[mdl@mdl helloworld]$ make clean
make -C /lib/modules/4.2.2-1-ARCH/build M=/home/mdl/Repos/Github/CLanguageReview/helloworld clean
make[1]: Entering directory '/usr/lib/modules/4.2.2-1-ARCH/build'
  CLEAN   /home/mdl/Repos/Github/CLanguageReview/helloworld/.tmp_versions
  CLEAN   /home/mdl/Repos/Github/CLanguageReview/helloworld/Module.symvers
make[1]: Leaving directory '/usr/lib/modules/4.2.2-1-ARCH/build'
```
## Module Load
```
[mdl@mdl helloworld]$ sudo make install
[sudo] password for mdl: 
insmod HelloWorld.ko
```
## Module unload
```
[mdl@mdl helloworld]$ sudo make uninstall
rmmod HelloWorld.ko
```
