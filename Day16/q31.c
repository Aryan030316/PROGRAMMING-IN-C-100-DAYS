/*
Q31: Write a program to take a number as input and print its equivalent binary representation.

Sample Test Cases:
Input 1:
10
Output 1:
1010

Input 2:
7
Output 2:
111
*/

#include <stdio.h>

int main() {
    unsigned int n;
    if (scanf("%u", &n) == 1) {
        if (n == 0) {
            printf("0\n");
            return 0;
        }
        int bits[32], idx = 0;
        while (n > 0) {
            bits[idx++] = n % 2;
            n /= 2;
        }
        for (int i = idx - 1; i >= 0; i--) {
            printf("%d", bits[i]);
        }
        printf("\n");
    }
    return 0;
}
