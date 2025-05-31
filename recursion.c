/*
There is a series, S, where the next term is the sum of pervious three terms. Given the first three terms of 
the series, a, b and c respectively, you have to output the nth term of the series using recursion.

Recursive method for calculating nth term is given below.
            / 
            | a                      n = 1
    S(n) = <  b                      n = 2
            | c                      n = 3
            | S(n-1)+S(n-2)+S(n-3)   otherwise
            \

Input Format
The first line contains a single integer, n.
The next line contains 3 space-separated integers, a, b, and c.

Constraints
1 <= n <= 20
1 <= a, b, c <= 100

Output Format
Print the nth term of the series, S(n).

Sample Input 0
5
1 2 3

Sample Output 0
11

Explanation 0
Consider the following steps:
1. S(1) = 1
2. S(2) = 2
3. S(3) = 3
4. S(4) = S(3)+S(2)+S(1)
5. S(5) = S(4)+S(3)+S(2)

From steps 1, 2, 3, and 4, we can say S(4) = 3 + 2 + 1 = 6; then using the values 
from step 2, 3, 4, and 5, we get S(5) = 6 + 3 + 2 . Thus, we print 11 as our answer.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


// int get_nth(int n, int n1, int n2, int n3){
//     int sum;
//     printf("n = %d\n", n);

//     // n = 4 
//     // sum1 = n1 + n2 + n3
//     // n = 5
//     // sum2 = sum + n1 + n2
//     // n = 6
//     // sum3 = sum2 + sum1 + n1
//     // n = 7
//     // sum4 = sum3 + sum2 + sum1
//     // n = 8 
//     // sum5 = sum4 + sum3 + sum2

//     if (n == 4) {
//         sum = n1 + n2 + n3;
//     } else {
//         while (n > 3) {
//             printf("adding numbers... \n");
//             n--;
            
//             return get_nth(n, n1, n2, n3);
//         }
//     }
    
//     return sum;
// }


int find_nth_term(int n, int a, int b, int c) {
  //Write your code here.
    if (n == 1){
        return a;
    } else if (n == 2){
        return b;
    } else if (n == 3){
        return c;
    } else {
        return find_nth_term(n-1, a, b, c) + find_nth_term(n-2, a, b, c) + find_nth_term(n-3, a, b, c);
    }
}

int main() {
    // int n, a, b, c;
    int n = 5, a = 1, b = 2, c = 3;
  
    // scanf("%d %d %d %d", &n, &a, &b, &c);
    int ans = find_nth_term(n, a, b, c);
 
    printf("%d\n\n\n\n", ans); 
    return 0;
}