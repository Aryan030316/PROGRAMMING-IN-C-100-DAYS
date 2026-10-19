/*
Q117: Write a program to take two sorted arrays of size m and n as input. Merge both the arrays such that the merged array is also sorted. Print the merged array.

Sample Test Cases:
Input 1:
nums1 = [2,7,11,15] nums2 = [4,8,10]
Output 1:
2 4 7 8 10 11 15

Input 2:
nums1 = [1,2,7] nums2 = [9,10,17]
Output 2:
1 2 7 9 10 17

Input 3:
nums1 = [-10,-2,7] nums2 = [-3, -1, 7]
Output 3:
-10 -3 -2 -1 7 7
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int parse_bracket_list(const char *start, const char *end, int *arr, int max_n) {
    int n = 0;
    const char *p = start;
    while (*p && p < end) {
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
    return n;
}

int main(void) {
    char buf[8192];
    size_t len = fread(buf, 1, sizeof(buf) - 1, stdin);
    buf[len] = '\0';

    int a[1000], b[1000], m = 0, n = 0;
    const char *lb1 = strchr(buf, '[');
    const char *rb1 = lb1 ? strchr(lb1, ']') : NULL;
    const char *lb2 = rb1 ? strchr(rb1 + 1, '[') : NULL;
    const char *rb2 = lb2 ? strchr(lb2, ']') : NULL;

    if (lb1 && rb1 && lb2 && rb2) {
        m = parse_bracket_list(lb1 + 1, rb1, a, 1000);
        n = parse_bracket_list(lb2 + 1, rb2, b, 1000);
    } else {
        const char *p = buf;
        int vals[2005], cnt = 0;
        while (*p) {
            if (*p == '-' || isdigit((unsigned char)*p)) {
                char *endp;
                long v = strtol(p, &endp, 10);
                if (endp != p) {
                    if (cnt < 2005) vals[cnt++] = (int)v;
                    p = endp;
                    continue;
                }
            }
            p++;
        }
        if (cnt >= 2) {
            int idx = 0;
            m = vals[idx++];
            for (int i = 0; i < m && idx < cnt && i < 1000; i++) a[i] = vals[idx++];
            if (idx < cnt) {
                n = vals[idx++];
                for (int i = 0; i < n && idx < cnt && i < 1000; i++) b[i] = vals[idx++];
            }
        }
    }

    int i = 0, j = 0, first = 1;
    while (i < m && j < n) {
        int val = (a[i] <= b[j]) ? a[i++] : b[j++];
        if (!first) putchar(' ');
        first = 0;
        printf("%d", val);
    }
    while (i < m) {
        if (!first) putchar(' ');
        first = 0;
        printf("%d", a[i++]);
    }
    while (j < n) {
        if (!first) putchar(' ');
        first = 0;
        printf("%d", b[j++]);
    }
    putchar('\n');
    return 0;
}
