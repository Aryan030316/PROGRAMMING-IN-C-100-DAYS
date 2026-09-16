/*
Q68: Delete an element from an array.

Sample Test Cases:
Input 1:
5
1 2 3 4 5
2
Output 1:
1 2 4 5
*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        int pos;
        if (scanf("%d", &pos) == 1) {
            for (int i = pos; i < n - 1; i++) {
                a[i] = a[i + 1];
            }
            for (int i = 0; i < n - 1; i++) {
                printf("%d%c", a[i], (i == n - 2 ? '\n' : ' '));
            }
        }
    }
    return 0;
}
