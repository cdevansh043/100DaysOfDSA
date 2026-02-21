// Problem: Given an array of integers, count the number of subarrays whose sum is equal to zero.
//
// Input:
// - First line: integer n
// - Second line: n integers
//
// Output:
// - Print the count of subarrays having sum zero
//
// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3
//
// Output:
// 6
//
// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    

    int count = 0;
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];

    for (int i = 0; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (prefix[i] == prefix[j])
                count++;

    printf("%d\n", count);
    return 0;
}