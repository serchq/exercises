/*
Problem Description

Given a string A consisting only of '(' and ')'.

You need to find whether parantheses in A is balanced or not ,if it is balanced then return 1 else return 0.



Problem Constraints
1 <= |A| <= 105



Input Format
First argument is an string A.



Output Format
Return 1 if parantheses in string are balanced else return 0.



Example Input
Input 1:

 A = "(()())"
Input 2:

 A = "(()"


Example Output
Output 1:

 1
Output 2:

 0


Example Explanation
Explanation 1:

 Given string is balanced so we return 1
Explanation 2:

 Given string is not balanced so we return 0
*/

/**
 * @input A : String termination by '\0'
 * 
 * @Output Integer
 */

 #include <stdio.h>
#include <string.h>

int solve(char* A) {
    int len = strlen(A);
    int i;
    int balance = 0;
    
    for (i = 0; i < len; i++){
        printf("%c ", A[i]);
        if (A[i] == '(')
            balance++;
        else if (A[i] == ')') {
            balance--;         
            if (balance < 0)
                return 0;
        }
    }    
    printf("\nbalance : %d\n", balance);
    if (balance == 0){
        return 1;
    }
    return 0;
}


int main(){
    // char A[] = "(()())";
    // char A[] = "(()";
    char A[] = "(()((((()(";
    // char A[] = "()";
    // char A[] = ")((";
    // char A[] = "))((()(())";
    
    int result;

    result = solve(A);
    printf("result = %d\n\n", result);

}