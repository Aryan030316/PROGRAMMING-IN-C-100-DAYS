/*
Q91: Remove all vowels from a string.

Sample Test Cases:
Input 1:
education
Output 1:
dctn
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char s[500];
    if (fgets(s, sizeof(s), stdin)) {
        for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != '\r'; i++) {
            char lower = tolower(s[i]);
            if (lower != 'a' && lower != 'e' && lower != 'i' && lower != 'o' && lower != 'u') {
                putchar(s[i]);
            }
        }
        putchar('\n');
    }
    return 0;
}
