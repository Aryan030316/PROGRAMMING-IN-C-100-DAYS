/*
Q96: Reverse each word in a sentence without changing the word order.

Sample Test Cases:
Input 1:
I love coding
Output 1:
I evol gnidoc
*/

#include <stdio.h>
#include <string.h>

static void reverse_range(char *s, int left, int right) {
    while (left < right) {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
    }
}

int main(void) {
    char s[1000];
    if (fgets(s, sizeof(s), stdin)) {
        size_t len = strlen(s);
        while (len > 0 && (s[len - 1] == '\n' || s[len - 1] == '\r')) {
            s[--len] = '\0';
        }
        int i = 0;
        while (s[i] != '\0') {
            while (s[i] == ' ') i++;
            if (s[i] == '\0') break;
            int start = i;
            while (s[i] != ' ' && s[i] != '\0') i++;
            reverse_range(s, start, i - 1);
        }
        printf("%s\n", s);
    }
    return 0;
}
