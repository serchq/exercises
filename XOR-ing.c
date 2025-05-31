/*************************************************************** 
Problem Description

Given an integer array A of size N.

You need to find the value obtained by XOR-ing the contiguous subarrays, followed by XOR-ing the values thus obtained. Determine and return this value.

For example, if A = [3, 4, 5] :

Subarray    Operation   Result
3       None            3
4       None            4
5       None            5
3,4   3 XOR 4         7
4,5   4 XOR 5         1
3,4,5    3 XOR 4 XOR 5   2

Now we take the resultant values and XOR them together:

3 ⊕ 4 ⊕ 5 ⊕ 7 ⊕ 1⊕ 2 = 6 we will return 6.



Problem Constraints
1 <= N <= 105

1 <= A[i] <= 108



Input Format
First and only argument is an integer array A.



Output Format
Return a single integer denoting the value as described above.



Example Input
Input 1:

 A = [1, 2, 3]
Input 2:

 A = [4, 5, 7, 5]


Example Output
Output 1:

 2
Output 2:

 0


Example Explanation
Explanation 1:

 1 ⊕ 2 ⊕ 3 ⊕  (1 ⊕ 2 ) ⊕ (2 ⊕ 3) ⊕ (1 ⊕ 2 ⊕ 3) = 2
Explanation 2:

 4 ⊕ 5 ⊕ 7 ⊕ 5 ⊕ (4 ⊕ 5) ⊕ (5 ⊕ 7) ⊕ (7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7) ⊕ (5 ⊕ 7 ⊕ 5) ⊕ (4 ⊕ 5 ⊕ 7 ⊕ 5) = 0
***************************************************************/
#include <stdio.h>
/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
int solve(int* A, int n1) {
    int i, j = 2;
    int xor, subset_xor;
    int start = 0;
    int end = 2;
    int size = 2;
    
    //     // Optimized Algorithm:
    // Iterate through the array and compute the frequency for each element.
    // If the frequency is odd, XOR the element into the result.
    // Return the final result.

    for (int i = 0; i < n1; i++) {
        // Calculate the frequency of A[i] in all subarrays
        // printf("calculating the frequency of A[%d] (%d)\n", i, A[i]);
        int frequency = (i + 1) * (n1 - i);
        // printf("frequency = %d\n", frequency);

        // If frequency is odd, include A[i] in the result
        if (frequency % 2 == 1) {
            printf("xoring A[%d] (%d)\n", i, A[i]);
            xor ^= A[i];
        }
    }

// //calculating xor for each subset_xor ignoring the individual elements and whole array
//     for (i = 0; i < n1; i++){
//         number_frequency = (i + 1) * (n1 - i);
    
//         if (number_frequency % 2 == 1){
//             xor ^= A[i];
//         }
//     }
    


    // //calculating xor for each subset 
    // for (size = 1; size <= n1; size++){
    //     // end = size;
    //     start = 0;
    //     do{
    //         printf("size = %d\n", size);
    //         // printf("end = %d\n", end);
    //         // xor-ing subsets
    //         printf("subset to xor: ");
    //         for (i = 0; i < size; i++){
    //             printf("(A[%d]) %d ", start+i, A[start+i]);
    //             subset_xor ^= A[start + i];
    //             // printf("j = %d \t; i = %d\n", i, j);
    //         }
    //         printf("subset xor = %d\n", subset_xor);
    //         start++;
    //         xor ^= subset_xor;
    //         subset_xor = 0;
    //         printf("xor with this subset: %d\n", xor);
    //         printf("\n");
    //     } while (start + size <= n1);
    // }


//   printf("subset to xor: ");
//         for (i = 0; i < n1; i++){
//             printf("(A[%d]) %d ", i, A[i]);
//             xor ^= A[i];
//             // printf("j = %d \t; i = %d\n", i, j);
//         }
//     printf("\n");
    return xor;
}

// for some reason, this works on the interviewBit page...
// int solve(int* A, int n1) {
//     int i;
//     int xor;
    
//     xor = A[0];
    
//     if (n1%2 == 0)
//         return 0;
//     else {
//         for (i=2; i<n1; i++){
//             xor ^= A[i];
//             i++;
//         }
//     }
    
//     return xor;
// }


void main(){
    // int A[3] = {1, 2, 3};
    // int A[4] = {4, 5, 7, 5};
    int A[61] = {18468, 6335, 26501, 19170, 15725, 11479, 29359, 26963, 24465, 5706, 28146, 23282, 16828, 9962, 492, 2996, 11943, 4828, 5437, 32392, 14605, 3903, 154, 293, 12383, 17422, 18717, 19719, 19896, 5448, 21727, 14772, 11539, 1870, 19913, 25668, 26300, 17036, 9895, 28704, 23812, 31323, 30334, 17674, 4665, 15142, 7712, 28254, 6869, 25548, 27645, 32663, 32758, 20038, 12860, 8724, 9742, 27530, 779, 12317, 3036};
    // int A[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    


    int totalSize = sizeof(A);
    int elementSize = sizeof(A[0]);
    int n1 = totalSize / elementSize;

    printf("XOR-ing the subarrays, the value is %d\n", solve(A, n1));

    printf("\n\n\n");
}



