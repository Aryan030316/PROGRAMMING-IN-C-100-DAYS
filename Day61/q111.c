/*
Q111: Write a program to take an integer array arr and an integer k as inputs. The task is to find the first negative integer in each subarray of size k moving from left to right. If no negative exists in a window, print "0" for that window. Print the results separated by spaces as output.

Sample Test Cases:
Input 1:
arr[] = [-8, 2, 3, -6, 10], k = 2
Output 1:
-8 0 -6 -6

Input 2:
arr[] = [12, -1, -7, 8, -15, 30, 16, 28], k = 3
Output 2:
-1 -1 -7 -15 -15 0

Input 3:
arr[] = [12, 1, 3, 5], k = 3
Output 3:
0 0
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

    int neg_q[1000], head = 0, tail = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) neg_q[tail++] = i;
        while (head < tail && neg_q[head] <= i - k) head++;
        if (i >= k - 1) {
            if (i > k - 1) putchar(' ');
            if (head < tail) printf("%d", arr[neg_q[head]]);
            else putchar('0');
        }
    }
    putchar('\n');
    return 0;
}
