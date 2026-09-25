/*
Q94: Find the longest word in a sentence.

Sample Test Cases:
Input 1:
I love programming
Output 1:
programming
*/

#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    if (fgets(s, sizeof(s), stdin)) {
        char longest[200] = """";
        int maxLen = 0;
        char current[200] = """";
        int curLen = 0;
        
        for (int i = 0; ; i++) {
            char ch = s[i];
            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\0') {
                if (curLen > maxLen) {
                    maxLen = curLen;
                    current[curLen] = '\0';
                    strcpy(longest, current);
                }
                curLen = 0;
                if (ch == '\0') break;
            } else {
                current[curLen++] = ch;
            }
        }
        printf("%s\n", longest);
    }
    return 0;
}
