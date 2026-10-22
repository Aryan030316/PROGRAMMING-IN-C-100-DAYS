/*
Q120: Write a program to take a string input. Change it to sentence case.

Sample Test Cases:
Input 1:
str = I am trying to build logic.
Output 1:
I Am Trying To Build Logic

Input 2:
str = The classes are supposed to start early.
Output 2:
The Classes Are Supposed To Start Early.

Input 3:
str = We are going to look at 26 different test cases.
Output 3:
We Are Going To Look At 26 Different Test Cases.
*/

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[4096];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    size_t len = strlen(buf);
    while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
        buf[--len] = '\0';
    }

    char *s = buf;
    if (strncmp(s, "str =", 5) == 0) {
        s += 5;
        while (*s == ' ') s++;
    }

    int new_word = 1;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        if (isspace(c)) {
            new_word = 1;
        } else if (isalpha(c)) {
            s[i] = new_word ? (char)toupper(c) : (char)tolower(c);
            new_word = 0;
        } else {
            new_word = 0;
        }
    }
    printf("%s\n", s);
    return 0;
}
