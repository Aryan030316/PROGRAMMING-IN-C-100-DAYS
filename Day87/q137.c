/*
Q137: Create an enum for user roles (ADMIN, USER, GUEST) and display messages based on role.

Sample Test Cases:
Input 1:
GUEST
Output 1:
Welcome Guest!
*/

#include <stdio.h>
#include <string.h>

enum Role { ADMIN, USER, GUEST };

int main(void) {
    char tok[32];
    if (scanf("%31s", tok) != 1) return 0;

    enum Role role;
    if (strcmp(tok, "ADMIN") == 0 || strcmp(tok, "0") == 0) role = ADMIN;
    else if (strcmp(tok, "USER") == 0 || strcmp(tok, "1") == 0) role = USER;
    else if (strcmp(tok, "GUEST") == 0 || strcmp(tok, "2") == 0) role = GUEST;
    else return 0;

    switch (role) {
        case ADMIN: printf("Welcome Admin!\n"); break;
        case USER: printf("Welcome User!\n"); break;
        case GUEST: printf("Welcome Guest!\n"); break;
    }
    return 0;
}
