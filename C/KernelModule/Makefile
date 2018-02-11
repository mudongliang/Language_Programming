DIRS = FileSystem helloworld listpractise moduleparam ModuleWrittenBefore printpid VFS

all:
	$(foreach dir,$(DIRS),$(MAKE) -C $(dir);)

clean:
	$(foreach dir,$(DIRS),$(MAKE) clean -C $(dir);)
