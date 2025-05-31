/*
Problem Description
Find the longest increasing subsequence of a given array of integers, A.
In other words, find a subsequence of array in which the subsequence's elements are in strictly increasing order, 
and in which the subsequence is as long as possible.
In this case, return the length of the longest increasing subsequence.

Problem Constraints
1 <= length(A) <= 2500
0 <= A[i] <= 2500

Input Format
The first and the only argument is an integer array A.

Output Format
Return an integer representing the length of the longest increasing subsequence.

Example Input
Input 1:
 A = [1, 2, 1, 5]
Input 2:
 A = [0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15]


Example Output
Output 1:
 3
Output 2:
 6


Example Explanation
Explanation 1:
 The longest increasing subsequence: [1, 2, 5]
Explanation 2:
 The possible longest increasing subsequences: [0, 2, 6, 9, 13, 15] or [0, 4, 6, 9, 11, 15] or [0, 4, 6, 9, 13, 15]
*/

//////////////////
/// study case ///
//////////////////

#include <stdio.h>
#include <stdlib.h>

#define MAX_N 2500

// Custom binary search function (equivalent to lower_bound)
int lowerBound(int* arr, int size, int key) {
    int left = 0, right = size - 1, mid;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (arr[mid] >= key)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return left; // The index where `key` should be placed
}

int lengthOfLIS(int* A, int n) {
    if (n == 0) return 0;

    int *dp = (int*)malloc(n * sizeof(int));
    int length = 0; // Length of LIS found so far

    for (int i = 0; i < n; i++) {
        int pos = lowerBound(dp, length, A[i]); // Find position using binary search
        dp[pos] = A[i]; // Replace or extend the sequence

        if (pos == length) // If a new element extends the LIS
            length++;
    }

    free(dp);
    return length;
}

int main() {
    int A[MAX_N], n;
    
    // Read the size of the array
    scanf("%d", &n);
    
    // Read array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    // Compute and print the length of LIS
    printf("%d\n", lengthOfLIS(A, n));

    return 0;
}