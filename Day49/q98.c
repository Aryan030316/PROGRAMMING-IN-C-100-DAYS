/*
Q98: Print initials of a name with the surname displayed in full.

Sample Test Cases:
Input 1:
John David Doe
Output 1:
J.D. Doe
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1000];
    if (fgets(s, sizeof(s), stdin)) {
        char *words[100];
        int count = 0;
        char *tok = strtok(s, " \t\r\n");
        while (tok != NULL && count < 100) {
            words[count++] = tok;
            tok = strtok(NULL, " \t\r\n");
        }
        if (count == 1) {
            printf("%s\n", words[0]);
        } else if (count > 1) {
            for (int i = 0; i < count - 1; i++) {
                printf("%c.", toupper((unsigned char)words[i][0]));
            }
            printf(" %s\n", words[count - 1]);
        }
    }
    return 0;
}
