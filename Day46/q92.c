/*
Q92: Find the first repeating lowercase alphabet in a string.

Sample Test Cases:
Input 1:
stress
Output 1:
s
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[500];
    if (scanf("%s", s) == 1) {
        int count[26] = {0};
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') {
                count[s[i] - 'a']++;
            }
        }
        char firstRep = '\0';
        for (int i = 0; s[i] != '\0'; i++) {
            if (s[i] >= 'a' && s[i] <= 'z' && count[s[i] - 'a'] > 1) {
                firstRep = s[i];
                break;
            }
        }
        if (firstRep != '\0')
            printf("%c\n", firstRep);
        else
            printf("None\n");
    }
    return 0;
}
