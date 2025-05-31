/*
Print a pattern of numbers from 1 to n as shown below. Each of the numbers is separated by a single space.

                            4 4 4 4 4 4 4  
                            4 3 3 3 3 3 4   
                            4 3 2 2 2 3 4   
                            4 3 2 1 2 3 4   
                            4 3 2 2 2 3 4   
                            4 3 3 3 3 3 4   
                            4 4 4 4 4 4 4   
Input Format

The input will contain a single integer n.

Constraints
1 <= n <= 1000

Sample Input 0
2

Sample Output 0
2 2 2
2 1 2
2 2 2

Sample Input 1
5

Sample Output 1
5 5 5 5 5 5 5 5 5 
5 4 4 4 4 4 4 4 5 
5 4 3 3 3 3 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 2 1 2 3 4 5 
5 4 3 2 2 2 3 4 5 
5 4 3 3 3 3 3 4 5 
5 4 4 4 4 4 4 4 5 
5 5 5 5 5 5 5 5 5

Sample Input 2
7

Sample Output 2
7 7 7 7 7 7 7 7 7 7 7 7 7 
7 6 6 6 6 6 6 6 6 6 6 6 7 
7 6 5 5 5 5 5 5 5 5 5 6 7 
7 6 5 4 4 4 4 4 4 4 5 6 7 
7 6 5 4 3 3 3 3 3 4 5 6 7 
7 6 5 4 3 2 2 2 3 4 5 6 7 
7 6 5 4 3 2 1 2 3 4 5 6 7 
7 6 5 4 3 2 2 2 3 4 5 6 7 
7 6 5 4 3 3 3 3 3 4 5 6 7 
7 6 5 4 4 4 4 4 4 4 5 6 7 
7 6 5 5 5 5 5 5 5 5 5 6 7 
7 6 6 6 6 6 6 6 6 6 6 6 7 
7 7 7 7 7 7 7 7 7 7 7 7 7 
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print_spiral(int n){
    int size = n + (n - 1);
    // printf("size: %d\n", size);
    int spiral[size][size];
    
    int left = 0, right = size-1, top = 0, bottom = size-1;
    
    while (n > 0){
        // printf("left = %d\ttop = %d\tright = %d\tbottom = %d\n", left, top, right, bottom);
        // -->
        for (int i = left; i <= right; i++){
            spiral[i][top] = n;
            // printf("[%d][%d] = %d\n", i, top, n);
        }
        top++;   
        // v
        for (int i = top; i <= bottom; i++){
            spiral[right][i] = n;
            // printf("[%d][%d] = %d\n", right, i, n);
        } 
        right--;
        // <--
        for(int i = right; i >= left; i--){
            spiral[i][bottom] = n;
            // printf("[%d][%d] = %d\n", i, bottom, n);
        }    
        bottom--;
        // // ^
        for(int i = bottom; i >= top; i--){
            spiral[left][i] = n;
            // printf("[%d][%d] = %d\n", left, i, n);
        }
        left++;
    
        n--;
    }
    
    // print result matrix
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            printf("%3d ", spiral[j][i]);
        }
        printf("\n");
    }    
}


int main() 
{

    int n;
    printf("size? ");

    scanf("%d", &n);
  	// Complete the code to print the pattern.
    print_spiral(n);
    
    return 0;
}