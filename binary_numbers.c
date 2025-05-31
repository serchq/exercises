/*
Objective
Today, we're working with binary numbers. Check out the Tutorial tab for learning materials and an instructional video!

Task
Given a base-10 integer, n, convert it to binary (base-2). Then find and print the base-10 integer denoting the 
maximum number of consecutive 1's in n's binary representation. When working with different bases, it is common to 
show the base as a subscript.

Example
n = 125
The binary representation of  125b10is 1111101b2. In base 10, there are 5 and 1 consecutive ones in two groups. 
Print the maximum, 5.

Input Format
A single integer, n.

Constraints
1 <= n <= 10^6

Output Format
Print a single base-10 integer that denotes the maximum number of consecutive 1's in the binary representation of n.

Sample Input 1
5

Sample Output 1
1

Sample Input 2
13

Sample Output 2
2

Explanation
Sample Case 1:
The binary representation of 5b10 is 101b2, so the maximum number of consecutive 1's is 1.
Sample Case 2:
The binary representation of 13b10 is 1101b2, so the maximum number of consecutive 1's is 2.

*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int continous_ones(int n){
    int count;
    int bit;
    int max = 0;
    
    if (n == 0){
        return 0;
    }
    
    while (n > 0){
        bit = n&1;      // extract LSB
        if (bit){
            count++;    // if it is a 1, increase counter
            if (count > max){
                max = count;
            }
        } else {
            count = 0;  // if not, restart it
        }
        n >>= 1;        // discard the read bit
    }
    
    return max;
}



int main()
{
    int n = 5;
    int n1 = 13;
    int n2 = 439;

    // printf("1s in %d (%b): %d\n", n, n, continous_ones(n));
    // printf("1s in %d (%b): %d\n", n1, n1, continous_ones(n1));
    printf("1s in %d (%b): %d\n", n2, n2, continous_ones(n2));

    return 0;
}
