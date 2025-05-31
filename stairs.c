/*************************************************************** 
You are climbing a stair case and it takes A steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?



Input Format:

The first and the only argument contains an integer A, the number of steps.
Output Format:

Return an integer, representing the number of ways to reach the top.
Constrains:

1 <= A <= 36

Example :

Input 1:
A = 2 

Output 1:
2 

Explanation 1:
[1, 1], [2] 

Input 2:
A = 3 

Output 2:
3 

Explanation 2: 
[1 1 1], [1 2], [2 1]


 * @input A : Integer
 * 
 * @Output Integer


***************************************************************/

#include <stdio.h>

int climbStairs(int A) {
    int i;

    if (A <= 2) {
        return A;
    }

    int dp[A + 1];
    dp[1] = 1; 
    dp[2] = 2; 

    for (i = 3; i <= A; i++){
        printf("dp[%d] = dp[%d-1] + dp[%d-2] = %d + %d\n", i, i, i, dp[i-1], dp[i-2]);
        dp[i] = dp[i-1] + dp[i-2];
        printf("dp[%d] = %d\n", i, dp[i]);
    }

    return (dp[A]);
}


void main() {
    int A; 
    int ways; 

    printf("how many stairs? ");
    scanf("%d", &A);

    ways = climbStairs(A);

    printf("there are %d ways\n\n\n", ways);
}