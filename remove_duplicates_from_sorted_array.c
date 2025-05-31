/*
Problem Description
 
Given a sorted array A consisting of duplicate elements.
Your task is to remove all the duplicates and return the length of the sorted array of distinct elements
consisting of all distinct elements present in A.
Note: You need to update the elements of array A by removing all the duplicates

Problem Constraints
1 <= |A| <= 106
1 <= Ai <= 2 * 109

Input Format
First and only argurment containing the integer array A.

Output Format
Return a single integer, as per the problem given.

Example Input
Input 1:
A = [1, 1, 2]

Input 2:
A = [1, 2, 2, 3, 3]

Example Output
Output 1:
2
Output 2:
3

Example Explanation
Explanation 1:
Updated Array: [1, 2, X] after rearranging. Note that there could be any number in place of x since we dont need it.
We return 2 here.

Explanation 2:
Updated Array: [1, 2, 3, X, X] after rearranging duplicates of 2 and 3.
We return 3 from here.
*/

/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */

#include <stdio.h>
#include <stdlib.h>

 int removeDuplicates(int* A, int n1) {
    int i;
    int newLen;
    int lastElement;
    int lastElementPos;

    newLen = 1; // there's at least 1 element by problem constrains. 
    lastElement = A[0];
    lastElementPos = 0; 
    
    if (n1 == 1)
        return 1;
    else {
        for (i = 1; i < n1; i++){
            printf("last element: %d\n", lastElement);
            if (A[i] != lastElement){
                newLen++;
                lastElement = A[i];
                lastElementPos++;
                A[lastElementPos] = lastElement;
                printf("new element! increasing counter\n");
                printf("A[%d] is now %d\n", lastElementPos, A[lastElementPos]);
            }
        }
    }

    return newLen;
}

void main(){
    // int A[3] = {1, 1, 2};
    // int A[5] = {1, 2, 2, 3, 3};
    // int A[10] = {1, 2, 8, 4, 5, 6, 7, 9, 9};
    // int A[1] = {1};
    int A[71] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3};
    int number;
  
    int totalSize = sizeof(A);
    int elementSize = sizeof(A[0]);
    int n1 = totalSize / elementSize;
  
    printf("length: %d\n", n1);
    number = removeDuplicates((int*)&A, n1);
    printf("\nnew length: %d\n\n\n\n\n\n", number);
    printf("new array: [ ");
    for (int i = 0; i < number; i++){
        printf("%d ", A[i]);
    }
    printf("]\n\n");
}
