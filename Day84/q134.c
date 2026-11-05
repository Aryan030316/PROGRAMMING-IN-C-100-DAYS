/*
Q134: Define an enum with SUCCESS, FAILURE, and TIMEOUT, and print messages accordingly.

Sample Test Cases:
Input 1:
FAILURE
Output 1:
Operation failed
*/

#include <stdio.h>
#include <string.h>

enum Status { SUCCESS, FAILURE, TIMEOUT };

int main(void) {
    char tok[32];
    if (scanf("%31s", tok) != 1) return 0;

    enum Status st;
    if (strcmp(tok, "SUCCESS") == 0 || strcmp(tok, "0") == 0) st = SUCCESS;
    else if (strcmp(tok, "FAILURE") == 0 || strcmp(tok, "1") == 0) st = FAILURE;
    else if (strcmp(tok, "TIMEOUT") == 0 || strcmp(tok, "2") == 0) st = TIMEOUT;
    else return 0;

    switch (st) {
        case SUCCESS: printf("Operation succeeded\n"); break;
        case FAILURE: printf("Operation failed\n"); break;
        case TIMEOUT: printf("Operation timed out\n"); break;
    }
    return 0;
}
