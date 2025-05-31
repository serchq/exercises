/*
Given an array of size N, find the majority element. The majority element is the element that appears more than floor(N/2) times.
You may assume that the array is non-empty and the majority element always exist in the array.



Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 109


Input Format
The first argument is an integer array A.


Output Format
Return the majority element.


Example Input
A = [2, 1, 2]


Example Output
2


Example Explanation
2 occurs 2 times which is greater than 3/2.

*/

#include <stdio.h>

int majorityElement(const int* A, int n1) {
    ///////////////////////////////////////////////////
    // first approach
    //////////////////////////////////////////////////
    
    // int counter[n1];
    // // int counter; 
    // int p;
    // int most; 
    // int i;
    
    // p = 0;    
    // printf("n1 = %d\n", n1);

    // if (n1 == 1){
    //     most = A[0];
    // }
    // else {
    //     do {
    //         printf("A[%d] = %d\n", p, A[p]);
    //         counter[p] = 0;
    //         for (i = p; i < n1; i++){
    //             if (A[i] == A[p]){
    //                 printf("counting one more %d in A[%d] = %d\n", A[p], i, A[i]);
    //                 counter[p]++;
    //                 printf("counter count = counter[%d] = %d\n", p, counter[p]);
    //                 if (counter[p] > (n1/2)){
    //                     most = A[p];
    //                     break;
    //                 }
    //             }     
    //         }
    //         if (most > 0){
    //             break;
    //         }
    //         p++;
    //     } while (p < n1);
    // }
    
    // printf("counter array: \n");
    // for (i = 0; i < n1; i++){
    //     printf("%d, ", counter[i]);
    // }
    // printf("\n");
    // return most;

    //////////////////////////////////////////////////
    // better approach
    //////////////////////////////////////////////////

    int candidate = -1, count = 0;

    // Step 1: Find a potential majority element
    for (int i = 0; i < n1; i++) {
        printf("candidate = A[%d] = %d\n", i, A[i]);
        if (count == 0) {
            printf("new count started\n");
            candidate = A[i];
            count = 1;
        } else if (A[i] == candidate) {
            count++;
            printf("found another one, increasing counter\n");
        } else {
            count--;
            printf("different number, decreasing counter\n");
        }
        printf("for i = %d, counter = %d\n\n", i, count);
    }

    // Step 2: The problem guarantees a majority element, so we can return candidate
    return candidate;

}

void main(){
    // int A[3] = {1, 1, 2};
    // int A[3] = {2, 1, 1};
    // int A[11] = {10, 20, 10, 20, 30, 30, 40, 30, 30, 30, 30};
    int A[11] = {10, 20, 10, 20, 10, 20, 10, 20, 10, 20, 20};
    // int A[13] = {24, 234, 12, 24, 52, 24, 674, 23, 24, 65, 24, 24, 24};
    // int A[1] = {100};
    // int A[2] = {2, 2};


    int totalSize = sizeof(A);
    int elementSize = sizeof(int);
    int n1 = totalSize / elementSize;

    int majority;


    majority = majorityElement(A, n1);

    printf("majority = %d", majority);


    printf("\n\n\n\n");
}




