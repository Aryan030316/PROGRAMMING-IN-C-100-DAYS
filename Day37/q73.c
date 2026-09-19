/*
Q73: Find the sum of each row of a matrix and store it in an array.

Sample Test Cases:
Input 1:
2 3
1 2 3
4 5 6
Output 1:
6 15
*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int rowSums[r];
        for (int i = 0; i < r; i++) {
            rowSums[i] = 0;
            for (int j = 0; j < c; j++) {
                int val;
                scanf("%d", &val);
                rowSums[i] += val;
            }
        }
        for (int i = 0; i < r; i++) {
            printf("%d%c", rowSums[i], (i == r - 1 ? '\n' : ' '));
        }
    }
    return 0;
}
