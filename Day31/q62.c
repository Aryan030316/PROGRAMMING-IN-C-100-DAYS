/*
Q62: Reverse an array without taking extra space.

Sample Test Cases:
Input 1:
4
1 2 3 4
Output 1:
4 3 2 1
*/

#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) == 1) {
        int a[n];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n / 2; i++) {
            int temp = a[i];
            a[i] = a[n - 1 - i];
            a[n - 1 - i] = temp;
        }
        for (int i = 0; i < n; i++) {
            printf("%d%c", a[i], (i == n - 1 ? '\n' : ' '));
        }
    }
    return 0;
}
