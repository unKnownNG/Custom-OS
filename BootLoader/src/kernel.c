void kernel_main() {
    // Pointer to the start of VGA text memory
    char* video_memory = (char*) 0xB8000;

    char* message = "Hello, OSDev World!";
    
    // Each character needs 2 bytes (char + color)
    // We'll use 0x07 for 'light grey on black'
    for (int i = 0; message[i] != '\0'; i++) {
        video_memory[i * 2] = message[i];      // Set character
        video_memory[i * 2 + 1] = 0x07;        // Set color attribute
    }

    // Don't forget the infinite loop we discussed!
    for(;;);
}