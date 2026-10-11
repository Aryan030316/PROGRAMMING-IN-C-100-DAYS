/*
Q109: Write a program to take an integer array arr and an integer k as inputs. Print the maximum sum of all the subarrays of size k.

Sample Test Cases:
Input 1:
arr[100, 200, 300, 400] = , k = 2
Output 1:
700

Input 2:
arr[1, 4, 2, 10, 23, 3, 1, 0, 20] = , k = 4
Output 2:
39

Input 3:
arr[100, 200, 300, 400] = , k = 1
Output 3:
400
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_array_and_k(const char *buf, int *arr, int max_n, int *k, int *has_k) {
    int n = 0;
    *has_k = 0;
    const char *lb = strchr(buf, '[');
    if (lb) {
        const char *rb = strchr(lb, ']');
        const char *p = lb + 1;
        while (*p && (!rb || p < rb)) {
            if (*p == '-' || isdigit((unsigned char)*p)) {
                char *endp;
                long v = strtol(p, &endp, 10);
                if (endp != p) {
                    if (n < max_n) arr[n++] = (int)v;
                    p = endp;
                    continue;
                }
            }
            p++;
        }
        if (rb) {
            p = rb + 1;
            while (*p) {
                if (*p == '-' || isdigit((unsigned char)*p)) {
                    char *endp;
                    long v = strtol(p, &endp, 10);
                    if (endp != p) {
                        *k = (int)v;
                        *has_k = 1;
                        break;
                    }
                }
                p++;
            }
        }
    } else {
        const char *p = buf;
        int vals[1005], cnt = 0;
        while (*p) {
            if (*p == '-' || isdigit((unsigned char)*p)) {
                char *endp;
                long v = strtol(p, &endp, 10);
                if (endp != p) {
                    if (cnt < 1005) vals[cnt++] = (int)v;
                    p = endp;
                    continue;
                }
            }
            p++;
        }
        if (cnt >= 2) {
            n = vals[0];
            if (n > cnt - 2) n = cnt - 2;
            for (int i = 0; i < n && i < max_n; i++) arr[i] = vals[i + 1];
            *k = vals[n + 1];
            *has_k = 1;
        }
    }
    return n;
}

int main(void) {
    char buf[8192];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    int arr[1000], k = 0, has_k = 0;
    int n = parse_array_and_k(buf, arr, 1000, &k, &has_k);
    if (n <= 0 || !has_k || k <= 0 || k > n) return 0;

    long long win = 0;
    for (int i = 0; i < k; i++) win += arr[i];
    long long best = win;
    for (int i = k; i < n; i++) {
        win += arr[i] - arr[i - k];
        if (win > best) best = win;
    }
    printf("%lld\n", best);
    return 0;
}
