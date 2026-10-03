/*
Q101: Write a Program to take a sorted array(say nums[]) and an integer (say target) as inputs. The elements in the sorted array might be repeated. You need to print the first and last occurrence of the target and print the index of first and last occurrence. Print -1, -1 if the target is not present.

Sample Test Cases:
Input 1:
nums = [5,7,7,8,8,10], target = 8
Output 1:
3,4

Input 2:
 nums = [5,7,7,8,8,10], target = 6
Output 2:
-1,-1

Input 3:
 nums = [5,7,7,8,8,10], target = 10
Output 3:
5,5
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_array_and_extra(const char *buf, int *arr, int max_n, int *extra, int *has_extra) {
    int n = 0;
    *has_extra = 0;
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
                        *extra = (int)v;
                        *has_extra = 1;
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
            *extra = vals[n + 1];
            *has_extra = 1;
        }
    }
    return n;
}

static int lower_bound(const int *arr, int n, int target) {
    int lo = 0, hi = n;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] < target) lo = mid + 1;
        else hi = mid;
    }
    return lo;
}

int main(void) {
    char buf[8192];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    int nums[1000], target = 0, has_target = 0;
    int n = parse_array_and_extra(buf, nums, 1000, &target, &has_target);
    if (n <= 0 || !has_target) return 0;

    int first = lower_bound(nums, n, target);
    if (first == n || nums[first] != target) {
        printf("-1,-1\n");
    } else {
        int last = lower_bound(nums, n, target + 1) - 1;
        printf("%d,%d\n", first, last);
    }
    return 0;
}
