/*
Q114: Write a program to take a string s as input. The task is to find the length of the longest substring without repeating characters. Print the length as output.

Sample Test Cases:
Input 1:
s = "abcabcbb"
Output 1:
3

Input 2:
s = "bbbbb"
Output 2:
1

Input 3:
s = "pwwkew"
Output 3:
3
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[4096];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    char s[4096];
    const char *q1 = strchr(buf, '"');
    const char *q2 = q1 ? strchr(q1 + 1, '"') : NULL;
    if (q1 && q2 && q2 > q1) {
        size_t len = (size_t)(q2 - (q1 + 1));
        memcpy(s, q1 + 1, len);
        s[len] = '\0';
    } else {
        size_t len = strlen(buf);
        while (len > 0 && (buf[len - 1] == '\n' || buf[len - 1] == '\r')) {
            buf[--len] = '\0';
        }
        strcpy(s, buf);
    }

    int last_seen[256];
    for (int i = 0; i < 256; i++) last_seen[i] = -1;

    int start = 0, best = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        unsigned char c = (unsigned char)s[i];
        if (last_seen[c] >= start) {
            start = last_seen[c] + 1;
        }
        last_seen[c] = i;
        int cur = i - start + 1;
        if (cur > best) best = cur;
    }
    printf("%d\n", best);
    return 0;
}
