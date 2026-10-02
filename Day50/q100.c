/*
Q100: Print all sub-strings of a string.

Sample Test Cases:
Input 1:
abc
Output 1:
a,ab,abc,b,bc,c
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char s[500];
    if (scanf("%499s", s) == 1) {
        int n = (int)strlen(s);
        int first = 1;
        for (int i = 0; i < n; i++) {
            for (int len = 1; len <= n - i; len++) {
                if (!first) putchar(',');
                first = 0;
                for (int k = 0; k < len; k++) {
                    putchar(s[i + k]);
                }
            }
        }
        putchar('\n');
    }
    return 0;
}
