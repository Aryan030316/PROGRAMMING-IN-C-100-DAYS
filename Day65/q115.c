/*
Q115: Write a program to take two strings s and t as inputs (assume all characters are lowercase). The task is to determine if s and t are valid anagrams, meaning they contain the same characters with the same frequencies. Print "Anagram" if they are, otherwise "Not Anagram".

Sample Test Cases:
Input 1:
s = "anagram", t = "nagaram"
Output 1:
Anagram

Input 2:
s = "rat", t = "car"
Output 2:
Not Anagram
*/

#include <stdio.h>
#include <string.h>

int main(void) {
    char buf[4096];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    char s[2048] = "", t[2048] = "";
    const char *q1 = strchr(buf, '"');
    const char *q2 = q1 ? strchr(q1 + 1, '"') : NULL;
    const char *q3 = q2 ? strchr(q2 + 1, '"') : NULL;
    const char *q4 = q3 ? strchr(q3 + 1, '"') : NULL;
    if (q1 && q2 && q3 && q4) {
        size_t l1 = (size_t)(q2 - (q1 + 1));
        size_t l2 = (size_t)(q4 - (q3 + 1));
        if (l1 >= sizeof(s)) l1 = sizeof(s) - 1;
        if (l2 >= sizeof(t)) l2 = sizeof(t) - 1;
        memcpy(s, q1 + 1, l1);
        s[l1] = '\0';
        memcpy(t, q3 + 1, l2);
        t[l2] = '\0';
    } else if (sscanf(buf, "%2047s %2047s", s, t) != 2) {
        return 0;
    }

    if (strlen(s) != strlen(t)) {
        printf("Not Anagram\n");
        return 0;
    }

    int freq[26] = {0};
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') freq[s[i] - 'a']++;
        if (t[i] >= 'a' && t[i] <= 'z') freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] != 0) {
            printf("Not Anagram\n");
            return 0;
        }
    }
    printf("Anagram\n");
    return 0;
}
