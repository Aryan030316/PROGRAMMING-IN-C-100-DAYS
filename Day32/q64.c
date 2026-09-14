/*
Q64: Find the digit that occurs the most times in an integer number.

Sample Test Cases:
Input 1:
112233
Output 1:
1

Input 2:
887799
Output 2:
7
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    if (scanf("%s", s) == 1) {
        int counts[10] = {0};
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                counts[s[i] - '0']++;
            }
        }
        int maxCount = 0, bestDigit = 0;
        for (int d = 0; d < 10; d++) {
            if (counts[d] > maxCount) {
                maxCount = counts[d];
                bestDigit = d;
            }
        }
        printf("%d\n", bestDigit);
    }
    return 0;
}
