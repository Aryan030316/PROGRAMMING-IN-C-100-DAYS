/*
Q79: Perform diagonal traversal of a matrix.

Sample Test Cases:
Input 1:
3 3
1 2 3
4 5 6
7 8 9
Output 1:
1 2 4 7 5 3 6 8 9
*/

#include <stdio.h>

int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) == 2) {
        int m[r][c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) scanf("%d", &m[i][j]);
        }
        int first = 1;
        for (int s = 0; s <= r + c - 2; s++) {
            if (s % 2 == 0) {
                int rStart = (s < r) ? s : r - 1;
                int cStart = s - rStart;
                while (rStart >= 0 && cStart < c) {
                    if (!first) printf(" ");
                    printf("%d", m[rStart][cStart]);
                    first = 0;
                    rStart--;
                    cStart++;
                }
            } else {
                int cStart = (s < c) ? s : c - 1;
                int rStart = s - cStart;
                while (cStart >= 0 && rStart < r) {
                    if (!first) printf(" ");
                    printf("%d", m[rStart][cStart]);
                    first = 0;
                    rStart++;
                    cStart--;
                }
            }
        }
        printf("\n");
    }
    return 0;
}
