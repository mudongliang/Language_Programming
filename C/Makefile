DIRS = apue.3e elf fork KernelModule libseccomp Network problem StackProtector sysprogram test useafterfree
# ldd3-examples : failed to compile

all:
	$(foreach dir,$(DIRS),$(MAKE) -C $(dir);)

clean:
	$(foreach dir,$(DIRS),$(MAKE) clean -C $(dir);)
