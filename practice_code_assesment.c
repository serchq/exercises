/*
Write a function:

class Solution { public int solution(int[] A); }

that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.

For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.

Given A = [1, 2, 3], the function should return 4.

Given A = [−1, −3], the function should return 1.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [−1,000,000..1,000,000].

*/
#include <stdio.h>
#include <stdlib.h>


int solution(int A[], int N) {
    // Implement your solution here
    int* counter = (int*)malloc(N+1 * sizeof(int));
    int min = 1;


    for (int i=0; i<N; i++){
        if (A[i] < 1){
            continue;
        }
        counter[A[i]]++;
    }
    
    // for (int i = 0; i<N; i++){
    //     printf("counter[%d] = %d\n", i, counter[i]);
    // }
    // printf("\n");

    for (int i = 1; i<=N; i++){
        printf("counter[%d] = %d\n", i, counter[i]);
        if (counter[i] == 0){
            min = i;
            printf("min = %d\n", min);
            free(counter);
            return min;
        }
    }

    printf("returning min_not_found = %d\n", min);
    free(counter);
    return N+1;
}


int main(){
    int A[6] = {1, 3, 6, 4, 1, 2};
    // int A[3] = {1, 2, 3};
    // int A[2] = {-1, -3};
    // int A[5] = {1, 2, 2, 6, 1};
  
    int number;

    int totalSize = sizeof(A);
    int elementSize = sizeof(A[0]);
    int n1 = totalSize / elementSize;   

    number = solution((int*)&A, n1);    
    
    printf("\nminimum int not present: %d\n", number);
}