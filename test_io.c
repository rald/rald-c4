int main() {
    int c;
    int counter;
    int running;
    
    printf("=== C4 Complete I/O & Delay Test Suite ===\n");
    printf("1. Testing delay() and kbhit() together.\n");
    printf("A dot will print every half second. Press any key to interrupt!\n");
    
    counter = 0;
    running = 1;
    
    while (running) {
        if (kbhit()) {
            printf("\n[!] Keypress detected via kbhit()!\n");
            running = 0; 
        } else {
            // putch() now uses write() internally and prints instantly!
            putch('.');
            
            delay(500); // Wait for 500 milliseconds (0.5 seconds)
            counter = counter + 1;
            if (counter >= 10) {
                running = 0; 
            }
        }
    }
    
    printf("\n\n2. Testing interactive getch() and putch().\n");
    printf("Type characters (press 'q' to quit):\n");
    
    running = 1;
    while (running) {
        c = getch();
        
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
