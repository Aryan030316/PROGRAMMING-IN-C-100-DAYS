/*
Q97: Print the initials of a name.

Sample Test Cases:
Input 1:
John Doe
Output 1:
J.D.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char s[1000];
    if (fgets(s, sizeof(s), stdin)) {
        int in_word = 0;
        for (int i = 0; s[i] != '\0'; i++) {
            if (!isspace((unsigned char)s[i])) {
                if (!in_word) {
                    printf("%c.", toupper((unsigned char)s[i]));
                    in_word = 1;
                }
            } else {
                in_word = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
