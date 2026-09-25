/*
Q85: Reverse a string.

Sample Test Cases:
Input 1:
abcd
Output 1:
dcba
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[500];
    if (fgets(s, sizeof(s), stdin)) {
        int len = 0;
        while (s[len] != '\0' && s[len] != '\n' && s[len] != '\r') len++;
        for (int i = len - 1; i >= 0; i--) {
            putchar(s[i]);
        }
        putchar('\n');
    }
    return 0;
}
