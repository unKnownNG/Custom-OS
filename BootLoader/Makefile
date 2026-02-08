FILES = build/kernel_entry.o build/kernel.o
FLAGS = -ffreestanding -nostdlib -Wall -O0 -Iinc

all: os-image

# Bootloader
boot:
	nasm -f bin src/boot.asm -o bin/boot.bin

# Kernel objects
kernel_objs:
	nasm -f elf32 src/kernel.asm -o build/kernel_entry.o
	i686-elf-gcc $(FLAGS) -std=gnu99 -m32 -c src/kernel.c -o build/kernel.o

# Link kernel (ELF)
kernel_elf:
	i686-elf-ld -T src/linkerScript.ld -m elf_i386 $(FILES) -o bin/kernel.elf

# Convert to flat binary
kernel_bin:
	i686-elf-objcopy -O binary bin/kernel.elf bin/kernel.bin

# Create OS image
os-image: boot kernel_objs kernel_elf kernel_bin
	dd if=/dev/zero of=bin/os.bin bs=512 count=2880
	dd if=bin/boot.bin of=bin/os.bin conv=notrunc
	dd if=bin/kernel.bin of=bin/os.bin bs=512 seek=1 conv=notrunc

clean:
	rm -rf bin/*
	rm -rf build/*
