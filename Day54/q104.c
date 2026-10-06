/*
Q104: Write a Program to take a positive integer n as input, and find the pivot integer x such that the sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively. Print the pivot integer x. If no such integer exists, print -1. Assume that it is guaranteed that there will be at most one pivot integer for the given input.

Sample Test Cases:
Input 1:
n = 8
Output 1:
6

Input 2:
n = 1
Output 2:
1

Input 3:
n = 4
Output 3:
-1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    char buf[256];
    if (!fgets(buf, sizeof(buf), stdin)) return 0;

    long long n = 0;
    int found = 0;
    for (const char *p = buf; *p; p++) {
        if (*p == '-' || isdigit((unsigned char)*p)) {
            n = strtoll(p, NULL, 10);
            found = 1;
            break;
        }
    }
    if (!found || n <= 0) return 0;

    long long total = n * (n + 1) / 2;
    long long lo = 1, hi = n, ans = -1;
    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;
        if (sq == total) {
            ans = mid;
            break;
        } else if (sq < total) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
