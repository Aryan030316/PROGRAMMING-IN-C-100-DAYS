/*
Q90: Toggle case of each character in a string.

Sample Test Cases:
Input 1:
Hello
Output 1:
hELLO
*/

#include <stdio.h>

int main() {
    char s[500];
    if (fgets(s, sizeof(s), stdin)) {
        for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != '\r'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') putchar(s[i] - ('a' - 'A'));
            else if (s[i] >= 'A' && s[i] <= 'Z') putchar(s[i] + ('a' - 'A'));
            else putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}
