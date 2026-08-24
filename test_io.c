int main() {
    int c;
    
    printf("Type characters (press 'q' to quit):\n");
    
    while (1) {
        c = getch();
        
        // If 'q' is pressed, exit the loop
        if (c == 'q') {
            printf("\nExiting...\n");
            return 0;
        }
        
        // Echo the character back using putch and print its ASCII value
        printf("\nRead character: ");
        putch(c);
        printf(" (ASCII: %d)\n", c);
    }
    return 0;
}
