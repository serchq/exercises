/*
////////////////////////////////////////////////////////////
////                                                    ////
////                Kadane's Algorithm                  ////
////                                                    ////
////////////////////////////////////////////////////////////

Problem Description
 
Find the contiguous subarray within an array, A of length N which has the largest sum.


Problem Constraints
1 <= N <= 106
-1000 <= A[i] <= 1000


Input Format
The first and the only argument contains an integer array, A.


Output Format
Return an integer representing the maximum possible sum of the contiguous subarray.


Example Input
Input 1:
A = [1, 2, 3, 4, -10]
Input 2:
A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]


Example Output
Output 1:
10
Output 2:
6


Example Explanation
Explanation 1:
The subarray [1, 2, 3, 4] has the maximum possible sum of 10.
Explanation 2:
The subarray [4,-1,2,1] has the maximum possible sum of 6.
*/

/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

#include <stdio.h>
#include <limits.h>

int maxSubArray(const int* A, int n1) {
    int i; 
    int sum = 0;
    int max_sum = INT_MIN;

    // max_sum = A[0];
    for (i = 0; i < n1; i++){
        printf("A[%d] = %d\n", i, A[i]);
        sum += A[i];
        printf("sum = %d\n", sum);
        if (sum > max_sum){
            max_sum = sum;
            printf("new max sum = %d\n\n", max_sum);
        } 
        if (sum < 0){
            printf("restarting max sum\n");
            sum = 0;
        } 
    
        printf("\n");
    }
    
    printf("\n");
    return max_sum;
}


void main(){
    // int A[5] = {1, 2, 3, 4, -10};
    // int A[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // int A[4] = {-3, -7, -4, -6};  // Only negatives
    int A[7] = {-307, -316, -236, -136, -323, -370, -386};

    int totalSize = sizeof(A);
    int elementSize = sizeof(int);
    int n1 = totalSize / elementSize;

    int max_sum;

    max_sum = maxSubArray(A, n1);

    printf("max sum = %d", max_sum);

    printf("\n\n\n\n");
}


