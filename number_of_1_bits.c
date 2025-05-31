/*************************************************************** 
Problem Description
 
 

Write a function that takes an integer and returns the number of 1 bits it has.


Problem Constraints
0 <= A <= 4294967295


Input Format
First and only argument contains integer A


Output Format
Return an integer as the answer


Example Input
Input1:
    11


Example Output
Output1:
3


Example Explanation
Explaination1:
11 is represented as 1101 in binary 
***************************************************************/
#include <stdio.h>

/**
 * @input A : Integer
 * 
 * @Output Integer
 */
int numSetBits(unsigned int A) {
    
    int bit;
    int counter;
    
    do{
        printf("A: %b\n", A);
        bit = A & 1;
        if (bit != 0)
            counter++;
        A = A>>1;
    } while (A > 0);

    return counter;
}


void main(){
    int A = 255;


    printf("number of 1s: %d", numSetBits(A));

    printf("\n\n\n");
}