/*
Given two integers n and m (m != 0). Find the number closest to n and divisible by m. 
If there is more than one such number, then output the one having maximum absolute value.

Examples: 

Input: n = 13, m = 4
Output: 12
Explanation: 12 is the closest to 13, divisible by 4.


Input: n = -15, m = 6
Output: -18
Explanation: Both -12 and -18 are closest to -15, but-18 has the maximum absolute value.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int closestNumber(int n, int m){
    int closest;
    int minDiff = INT_MAX;
    int diff;
    int i;

    for (i = n - abs(m); i <= n + abs(m); i++){
        if (i % m == 0){
            diff = abs(n-i);

            if ((diff < minDiff) || (diff == minDiff && abs(i) > abs(closest))){
                closest = i;
                minDiff = diff;
            }
        }
    }

    return closest;
}

int closestNumber2(int n, int m) {
    // find the quotient
    int q = n / m;
    printf("q = n / m = %d / %d = %d\n", n, m, q);

    // 1st possible closest number
    int n1 = m * q;
    printf("1st possible closest = m * q = %d * %d = %d\n", m, q, n1);

    // 2nd possible closest number
    int n2 = (n * m) > 0 ? (m * (q + 1)) : (m * (q - 1));
    printf("2st possible closest = m * q(+ - 1) = %d * %d(+ - 1) = %d\n", m, q, n2);
    
    // if true, then n1 is the required closest number
    if (abs(n - n1) < abs(n - n2))
        return n1;
    
    // else n2 is the required closest number    
    return n2;    
}



int main(){
    int closest;
    
    // int n = 13;
    // int m = 4;

    int n = -15;
    int m = 6;

    closest = closestNumber(n, m);
    printf("the closest number is: %d\n", closest);

    closest = closestNumber2(n, m);
    printf("the closest number is: %d\n", closest);

    printf("\n\n\n\n");
    return 0;
}