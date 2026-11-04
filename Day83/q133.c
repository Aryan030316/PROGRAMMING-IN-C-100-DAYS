/*
Q133: Create an enum for months and print how many days each month has.

Sample Test Cases:
Input 1:
FEB
Output 1:
28 or 29 days
*/

#include <stdio.h>
#include <string.h>

enum Month {
    JAN = 1, FEB, MAR, APR, MAY, JUN,
    JUL, AUG, SEP, OCT, NOV, DEC
};

int main(void) {
    const char *names[] = {
        "", "JAN", "FEB", "MAR", "APR", "MAY", "JUN",
        "JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
    };
    char tok[16];
    if (scanf("%15s", tok) != 1) return 0;

    int m = 0;
    for (int i = JAN; i <= DEC; i++) {
        if (strcmp(tok, names[i]) == 0) {
            m = i;
            break;
        }
    }
    if (m == 0) return 0;

    switch ((enum Month)m) {
        case FEB:
            printf("28 or 29 days\n");
            break;
        case APR:
        case JUN:
        case SEP:
        case NOV:
            printf("30 days\n");
            break;
        default:
            printf("31 days\n");
            break;
    }
    return 0;
}
