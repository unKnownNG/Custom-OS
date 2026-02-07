# Custom-OS

A small hobby operating system I'm building from scratch. This repository contains my bootloader and early-stage OS code (assembly, C, linker scripts, and build tooling).

## Project Goals

- Learn how operating systems work by implementing core components from scratch.
- Implement a simple bootloader that loads a kernel into memory and transfers control.
- Build a minimal kernel with basic driver support, memory management, multitasking, and a tiny userspace.
- Document the design and provide reproducible build/run steps.

## Current Status

- Bootloader: Implemented (Assembly). It can boot and load a kernel image into memory.
- Kernel: Early-stage. Skeleton kernel sources and linker scripts present (C + Linker Script).
- Build system: Makefiles for assembling, linking and producing a bootable image.


## Repository layout (recommended)

- /boot/          - Bootloader sources and build artifacts (assembly, linker script)
- /kernel/        - Kernel C sources and headers
- /include/       - Shared headers
- /build/         - Generated build output (ISO, binary images)
- /tools/         - Helper scripts (mkimg, build helpers)
- Makefile        - Top-level build script


## Prerequisites

- x86 cross-toolchain (gcc, ld, objcopy) targeting i386 or x86_64 depending on your kernel. Example:

```sh
# On Debian/Ubuntu you can install the following packages:
sudo apt-get install qemu-system-x86 build-essential nasm gcc-multilib
```

- nasm (or your assembler) for assembly bootloader sources
- qemu for running the image locally

## Build

From the repository root, run:

```sh
make all
```

This will assemble the bootloader, compile/link the kernel, and produce a bootable image in `build/` (e.g. `build/os.img` or `build/boot.iso`).

If your Makefile uses a different target, run `make` or `make <target>` as appropriate.

## Run (QEMU)

Run the built image with QEMU (example):

```sh
# For BIOS-style boot on x86:
qemu-system-i386 -drive format=raw,file=build/os.img

# Or for ISO boot (if you produce an ISO):
qemu-system-x86_64 -cdrom build/boot.iso
```

Adjust the qemu binary and flags for your target architecture.

## Debugging

- Use `-serial stdio` or `-nographic` to see kernel output on the console.
- Use `-s -S` and connect GDB for low-level debugging:

```sh
qemu-system-i386 -drive format=raw,file=build/os.img -s -S
# Then in another terminal:
gdb -q build/kernel.elf
(gdb) target remote :1234
```
 
## Development roadmap / next steps

- Implement basic VGA/text output driver and logging
- Set up protected mode / long mode transition (depending on architecture)
- Implement memory management (paging, heap allocator)
- Set up interrupt descriptor table (IDT) and basic interrupt handling
- Add simple task switching / scheduler
- Implement basic drivers (timer, keyboard, disk)

## Contributing

Contributions welcome. For substantial changes, please open an issue first to discuss design and compatibility.

- Fork the repo
- Create a feature branch
- Open a pull request with a clear description and tests/steps to reproduce


## Contact

If you want help or to collaborate, open an issue or reach out via the contact information in your GitHub profile.

