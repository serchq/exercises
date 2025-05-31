#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  int max_and = 0; 
  int max_or = 0;
  int max_xor = 0;
  
  printf("%04b\n%04b\n%04b\n\n", max_and, max_or, max_xor);

  for (int i = 1; i <= n; i++){
    for (int j = i+1; j <= n; j++){
        printf("a & b = %04b & %04b = %04b\n", i, j, i&j);
        if (((i & j) > max_and) && (i & j) < k) {
            printf("new max\n");
            max_and = i & j;            
        }
        printf("a | b = %04b | %04b = %04b \n", i, j, i|j);
        if (((i | j) > max_or) && (i | j) < k) {
            printf("new max\n");
            max_or = i | j;            
        }
        printf("a ^ b = %04b ^ %04b = %04b\n", i, j, i^j);
        if (((i ^ j) > max_xor) && (i ^ j) < k) {
            printf("new max\n");
            max_xor = i ^ j;            
        }
        printf("\n");
        printf("%04b (%d)\n%04b (%d)\n%04b (%d)\n\n", max_and,max_and, max_or, max_or, max_xor, max_xor);      
    }
  }
  
//   printf("%04b (%d)\n%04b (%d)\n%04b (%d)\n", max_and,max_and, max_or, max_or, max_xor, max_xor);
  
  
}

int main() {
    int n = 3, k = 2;
      
    calculate_the_maximum(n, k);
 
    return 0;
}