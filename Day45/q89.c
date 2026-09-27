/*
Q89: Count frequency of a given character in a string.

Sample Test Cases:
Input 1:
programming
g
Output 1:
2
*/

#include <stdio.h>

int main() {
    char s[500];
    char ch;
    if (scanf("%s", s) == 1) {
        if (scanf(" %c", &ch) == 1) {
            int freq = 0;
            for (int i = 0; s[i] != '\0'; i++) {
                if (s[i] == ch) freq++;
            }
            printf("%d\n", freq);
        }
    }
    return 0;
}
