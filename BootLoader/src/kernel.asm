[BITS 32]
global _start
extern kernel_main

_start:
    mov esp, 0x9C00     ; SAFE STACK
    call kernel_main

.hang:
    cli
    hlt
    jmp .hang
