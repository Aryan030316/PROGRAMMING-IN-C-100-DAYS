/*
Q67: Insert an element in an array at a given position.

Sample Test Cases:
Input 1:
4
10 20 30 40
2 15
Output 1:
10 20 15 30 40
*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int a[n + 1];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int pos, val;
        if (scanf("%d %d", &pos, &val) == 2) {
            for (int i = n; i > pos; i--) {
                a[i] = a[i - 1];
            }
            a[pos] = val;
            for (int i = 0; i <= n; i++) {
                printf("%d%c", a[i], (i == n ? '\n' : ' '));
            }
        }
    }
    return 0;
}
