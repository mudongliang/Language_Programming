target := helloworld

all: $(target)

%.o : %.asm
	nasm -f elf $< -o $@

% : %.o
	ld -m elf_i386 $< -o $@

clean:
	rm -rf $(target) *.o
