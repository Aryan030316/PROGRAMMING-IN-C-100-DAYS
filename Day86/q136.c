/*
Q136: Use enum to represent menu choices (ADD, SUBTRACT, MULTIPLY) and perform operations using switch.

Sample Test Cases:
Input 1:
ADD 10 20
Output 1:
30
*/

#include <stdio.h>
#include <string.h>

enum Operation { ADD, SUBTRACT, MULTIPLY };

int main(void) {
    char op_str[32];
    int x, y;
    if (scanf("%31s %d %d", op_str, &x, &y) != 3) return 0;

    enum Operation op;
    if (strcmp(op_str, "ADD") == 0 || strcmp(op_str, "0") == 0) op = ADD;
    else if (strcmp(op_str, "SUBTRACT") == 0 || strcmp(op_str, "1") == 0) op = SUBTRACT;
    else if (strcmp(op_str, "MULTIPLY") == 0 || strcmp(op_str, "2") == 0) op = MULTIPLY;
    else return 0;

    switch (op) {
        case ADD: printf("%d\n", x + y); break;
        case SUBTRACT: printf("%d\n", x - y); break;
        case MULTIPLY: printf("%d\n", x * y); break;
    }
    return 0;
}
