/*
1. Write  a C function to set "n" bits in a 32-bit number X.


2. Write a C function to mimic sizeof() operator.

*/

#include <stdio.h>
#include <stdint.h>


#define my_sizeof(type) ((char *)(&type + 1) - (char *)(&type))  // increments the pointer by 1, and then substract the pointer of the type
                                                                // pretty fucking simple...


uint32_t set_bits(int X, int n){

  if (n >= 32){
    X = 0xFFFF;
  }
  return X | ((1U << n) - 1);   // mask defined by shifting 1 'n' times, and then doing 2's complement.

}



int main (){
  int X = 15428;
  int n = 0;

  printf("%b\n", X);
  printf("%b\n\n", set_bits(X, 7));


  int x;
  double y;
  char z;
  int arr[10];

  printf("%lu\n", my_sizeof(x));
  printf("%lu\n", my_sizeof(y));
  printf("%lu\n", my_sizeof(z));
  printf("%lu\n", my_sizeof(arr));

  printf("\n\n\n");
  return 0;

}
