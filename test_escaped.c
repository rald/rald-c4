// test_escaped.c - Testing escape sequences in c4.c

int main() {
    // Declarations
    char *s;
    char c1;
    char c2;

    // 1. Test standard control characters and literals
    printf("Line 1: Newline test\nLine 2: Tab\tcheck\n");
    printf("Backslash: \\, Double Quote: \", Single Quote: '\n");

    // 2. Test hex escape sequence (\x41 is 'A')
    printf("Hex test (\x41\x42\x43): ABC expected -> \x41\x42\x43\n");

    // 3. Test null character embedding in strings
    s = "Hello\0World";
    printf("Null-terminated test: %s (should print Hello only)\n", s);

    // 4. Test character literals with escapes
    c1 = '\n';
    c2 = '\x41';
    
    if (c2 == 'A') {
        printf("Character literal hex escape passed!\n");
    }

    return 0;
}
