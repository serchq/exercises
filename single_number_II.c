/**
 * Problem Description
 
Given an array of integers, every element appears thrice except for one, which occurs once.
 Find that element that does not appear thrice.
 NOTE: Your algorithm should have a linear runtime complexity.
 Can you implement it without using extra memory?



Problem Constraints
2 <= A <= 5*106
0 <= A <= INTMAX



Input Format
First and only argument of input contains an integer array A.



Output Format
Return a single integer.



Example Input
Input 1:

 A = [1, 2, 4, 3, 3, 2, 2, 3, 1, 1]
Input 2:

 A = [0, 0, 0, 1]


Example Output
Output 1:

 4
Output 2:

 1


Example Explanation
Explanation 1:

 4 occurs exactly once in Input 1.
 1 occurs exactly once in Input 2.
 * 
 */


/**
 * @input A : Read only ( DON'T MODIFY ) Integer array
 * @input n1 : Integer array's ( A ) length
 * 
 * @Output Integer
 */
#include <stdio.h>

 int singleNumber(const int* A, int n1) {
    int i;
    int once = 0;
    int twice = 0;


        // for (i = 1; i < n1; i++){
            // num ^= A[i];
        //   }
        

    for (i = 0; i < n1; i++){
        // printf("once = (%04b ^ A[%d]) & %04b = (%04b ^ %04b) & %04b = %04b & %04b = ", once, i, ~twice, once, A[i], ~twice, once ^ A[i], ~twice);
        once = (once ^ A[i]) & ~twice; 
        // printf("%04b\n", once);
        // printf("twice = (%04b ^ A[%d]) & %04b = (%04b ^ %04b) & %04b = %04b & %04b = ", twice, i, ~once, twice, A[i], ~once, twice ^ A[i], once);
        twice = (twice ^ A[i]) & ~once;
        // printf("%04b\n\n", twice);
    }

    return once;

    // int i = 0; 
    // int counter[n1][2];
    // int ret;
    // int p; 

    // for (i = 0; i < n1; i++){
    //     counter[p][0] = A[i];
    //     counter[p][1]++;
    //     printf("increasing counter[A[%d]] = counter[%d][1] = %d\n", p, A[i], counter[A[i]]);
        
    // }

    // for (i = 0; i < n1; i++){
    //     printf("counter[%d] = %d\n", i, counter[i]);
    //     if (counter[i] == 1){
    //         ret = i;
    //     }
    // }

    // return ret;
}



int main() {
    // int A[5] = {1, 2, 2, 3, 1};
    // int A[167] = {723, 256, 668, 723, 140, 360, 597, 233, 128, 845, 737, 804, 986, 701, 906, 512, 845, 510, 510, 227, 430, 701, 366, 946, 464, 619, 946, 627, 209, 771, 424, 555, 959, 711, 530, 937, 716, 261, 505, 658, 706, 140, 511, 277, 396, 233, 819, 196, 475, 906, 583, 261, 147, 658, 517, 197, 196, 702, 944, 711, 128, 555, 149, 483, 530, 291, 716, 258, 430, 464, 601, 749, 149, 415, 802, 573, 627, 771, 660, 601, 360, 986, 291, 51, 415, 51, 227, 258, 937, 366, 923, 669, 33, 517, 417, 702, 475, 706, 110, 417, 275, 804, 500, 473, 746, 973, 669, 275, 973, 147, 817, 657, 277, 923, 144, 660, 197, 511, 793, 893, 944, 505, 322, 817, 586, 512, 322, 668, 33, 424, 962, 597, 144, 746, 345, 753, 345, 269, 819, 483, 368, 802, 573, 962, 583, 615, 208, 209, 269, 749, 256, 657, 619, 893, 959, 473, 753, 299, 396, 299, 500, 368, 586, 110, 793, 737, 615};
    // int A[5] = {1, 2, 2, 7, 1};
    // int A[10] = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
    // int A[4] = {0, 0, 0, 1};
    // int A[7] = {1, 2, 2, 7, 2, 1, 1};
    int A[4] = {5, 5, 1, 5};
  
    
    int number;
  
    int totalSize = sizeof(A);
    int elementSize = sizeof(A[0]);
    int n1 = totalSize / elementSize;
  
    number = singleNumber((int*)&A, n1);
  
    printf("\nsingle number: %d\n", number);
  }