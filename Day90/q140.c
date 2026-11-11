/*
Q140: Define a struct with enum Gender and print person's gender.

Sample Test Cases:
Input 1:
Gender=MALE
Output 1:
Male
*/

#include <stdio.h>
#include <string.h>

enum Gender { MALE, FEMALE, OTHER };

struct Person {
    enum Gender gender;
};

int main(void) {
    char buf[128];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    char *val = buf;
    char *eq = strchr(buf, '=');
    if (eq) val = eq + 1;

    char tok[32];
    if (sscanf(val, "%31s", tok) != 1) return 0;

    struct Person p;
    if (strcmp(tok, "MALE") == 0 || strcmp(tok, "0") == 0) p.gender = MALE;
    else if (strcmp(tok, "FEMALE") == 0 || strcmp(tok, "1") == 0) p.gender = FEMALE;
    else p.gender = OTHER;

    switch (p.gender) {
        case MALE: printf("Male\n"); break;
        case FEMALE: printf("Female\n"); break;
        case OTHER: printf("Other\n"); break;
    }
    return 0;
}
