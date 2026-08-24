int main() {
    int c;
    int counter;
    int running;
    
    printf("=== C4 I/O Test Suite ===\n");
    printf("1. Testing non-blocking kbhit() loop. Type any key to stop it:\n");
    
    counter = 0;
    running = 1;
    
    while (running) {
        if (kbhit()) {
            printf("\n[!] Keypress detected via kbhit()!\n");
            running = 0; // Turn off flag instead of using break
        } else {
            // Print a progress indicator without blocking
            putch('.');
            counter = counter + 1;
            if (counter > 50) {
                running = 0;
            }
        }
    }
    
    printf("\n\n2. Testing interactive getch() and putch().\n");
    printf("Type characters (press 'q' to quit):\n");
    
    running = 1;
    while (running) {
        c = getch();
        
        // Exit condition if 'q' is pressed
        if (c == 'q') {
            printf("\nExiting I/O test. Goodbye!\n");
            running = 0;
        } else {
            printf("\nYou typed: ");
            putch(c);
            printf(" (ASCII: %d)\n", c);
        }
    }
    
    return 0;
}
