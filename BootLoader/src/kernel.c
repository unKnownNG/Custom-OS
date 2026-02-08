void kernel_main(void) {
    volatile char* video_memory = (volatile char*)0xB8000;

    // Start at row 1, column 0
    int offset = 80 * 2;  // one line down

    const char* message = "Hello, OSDev World!";

    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[offset + i * 2] = message[i];
        video_memory[offset + i * 2 + 1] = 0x0F;
    }

    for (;;) {
        __asm__ volatile ("hlt");
    }
}
