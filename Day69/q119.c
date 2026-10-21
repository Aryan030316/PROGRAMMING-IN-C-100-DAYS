/*
Q119: Write a program to take an integer array as input. Only one element will be repeated. Print the repeated element. Try to find the result in one single iteration.

Sample Test Cases:
Input 1:
nums1 = [1,3,3,4]
Output 1:
3

Input 2:
nums1 = [1,2,2]
Output 2:
2

Input 3:
nums1 = [0,4,1,1,5]
Output 3:
1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_array(const char *buf, int *arr, int max_n) {
    int n = 0;
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
        if (cnt >= 1) {
            n = vals[0];
            if (n > cnt - 1) n = cnt - 1;
            for (int i = 0; i < n && i < max_n; i++) arr[i] = vals[i + 1];
        }
    }
    return n;
}

int main(void) {
    char buf[8192];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    int nums[1000];
    int n = parse_array(buf, nums, 1000);
    if (n <= 0) return 0;

    static unsigned char seen[100001];
    for (int i = 0; i < n; i++) {
        if (nums[i] >= 0 && nums[i] <= 100000) {
            if (seen[nums[i]]) {
                printf("%d\n", nums[i]);
                return 0;
            }
            seen[nums[i]] = 1;
        }
    }
    return 0;
}
