/*
Q116: Write a program to take an integer array nums which contains only positive integers, and an integer target as inputs. The goal is to find two distinct indices i and j in the array such that nums[i] + nums[j] equals the target. Assume exactly one solution exists and return the indices in any order. Print the two indices separated by a space as output. If no solution exists, print "-1 -1".

Sample Test Cases:
Input 1:
nums = [2,7,11,15], target = 9
Output 1:
0 1

Input 2:
nums = [3,2,4], target = 6
Output 2:
1 2

Input 3:
nums = [3,3], target = 6
Output 3:
0 1
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_array_and_target(const char *buf, int *arr, int max_n, int *target, int *has_target) {
    int n = 0;
    *has_target = 0;
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
                        *target = (int)v;
                        *has_target = 1;
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
            *target = vals[n + 1];
            *has_target = 1;
        }
    }
    return n;
}

int main(void) {
    char buf[8192];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    int nums[1000], target = 0, has_target = 0;
    int n = parse_array_and_target(buf, nums, 1000, &target, &has_target);
    if (n <= 0 || !has_target) return 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (nums[i] + nums[j] == target) {
                printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("-1 -1\n");
    return 0;
}
