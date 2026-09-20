/*
Q83: Count vowels and consonants in a string.

Sample Test Cases:
Input 1:
hello
Output 1:
Vowels=2, Consonants=3
*/

#include <stdio.h>
#include <ctype.h>

int main() {
    char s[500];
    if (fgets(s, sizeof(s), stdin)) {
        int v = 0, c = 0;
        for (int i = 0; s[i] != '\0' && s[i] != '\n' && s[i] != '\r'; i++) {
            char ch = tolower(s[i]);
            if (ch >= 'a' && ch <= 'z') {
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                    v++;
                else
                    c++;
            }
        }
        printf("Vowels=%d, Consonants=%d\n", v, c);
    }
    return 0;
}
