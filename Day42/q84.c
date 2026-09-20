/*
Q84: Convert a lowercase string to uppercase without using built-in functions.

Sample Test Cases:
Input 1:
hello
Output 1:
HELLO
*/

#include <stdio.h>

int main() {
    char s[500];
    if (fgets(s, sizeof(s), stdin)) {
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                s[i] = s[i] - ('a' - 'A');
            }
        }
        printf("%s", s);
    }
    return 0;
}
