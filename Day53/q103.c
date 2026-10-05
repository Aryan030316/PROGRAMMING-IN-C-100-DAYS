/*
Q103: Write a Program to take an array of integers as input, calculate the pivot index of this array. The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right. If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array. Print the leftmost pivot index. If no such index exists, print -1.

Sample Test Cases:
Input 1:
nums = [1,7,3,6,5,6]
Output 1:
3

Input 2:
nums = [1,2,3]
Output 2:
-1

Input 3:
nums = [2,1,-1]
Output 3:
0
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

    long long total = 0;
    for (int i = 0; i < n; i++) total += nums[i];

    long long left_sum = 0;
    int pivot = -1;
    for (int i = 0; i < n; i++) {
        long long right_sum = total - left_sum - nums[i];
        if (left_sum == right_sum) {
            pivot = i;
            break;
        }
        left_sum += nums[i];
    }
    printf("%d\n", pivot);
    return 0;
}
