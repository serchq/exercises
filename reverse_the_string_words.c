/*
Problem Description
 
You are given a string A of size N.
Return the string A after reversing the string word by word.

NOTE:
A sequence of non-space characters constitutes a word.
Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
If there are multiple spaces between words, reduce them to a single space in the reversed string.
 
Problem Constraints
1 <= N <= 3 * 105

Input Format
The only argument given is string A.

Output Format
Return the string A after reversing the string word by word.

Example Input
Input 1:
    A = "the sky is blue"
Input 2:
    A = "this is ib"

Example Output
Output 1:
    "blue is sky the"
Output 2:
    "ib is this"


Example Explanation
Explanation 1:
    We reverse the string word by word so the string becomes "the sky is blue".
Explanation 2:
    We reverse the string word by word so the string becomes "this is ib".
*/

/**
 * @input A : String termination by '\0'
 * 
 * @Output string. Make sure the string ends with null character
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function to reverse a portion of a string in place
void reverse(char *str, int start, int end) {
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to remove extra spaces and reverse words in-place
char* solve(char *A) {
    int n = strlen(A);
    if (n == 0) return A;

    int i = 0, j = 0;

    // Step 1: Remove leading and multiple spaces while copying in place
    while (i < n) {
        if (A[i] == ' ' && (j == 0 || A[j - 1] == ' ')) {
            i++;  // Skip multiple spaces
        } else {
            A[j++] = A[i++];  // Copy character
        }
    }

    // Remove trailing space if present
    if (j > 0 && A[j - 1] == ' ') j--;
    A[j] = '\0';  // Null-terminate the new string
    n = j;        // Update new length

    // Step 2: Reverse the entire string
    reverse(A, 0, n - 1);

    // Step 3: Reverse individual words
    int start = 0;
    for (i = 0; i <= n; i++) {
        if (A[i] == ' ' || A[i] == '\0') {
            reverse(A, start, i - 1);
            start = i + 1;
        }
    }
}


void reverseWords(char* s)
{
    int l= strlen(s);
    int flag=0,i=l-1,c=0;
  //  printf("%d\n",l);
    char*ans =(char*)malloc(sizeof(char)*l);
    
    while(i>=0)
    {
        int j=i;
        if(s[i] != ' ') { // consider only letter characters
            while(s[i]!= ' ' && i>0)   // find the last word in the array
                i--;
        
            int k;
            for(k = i+1; k<=j; k++) {
                // c++;
                ans[c++]= s[k];
                // printf("%c",ans[c]);
            }
            // printf("--");
            if(i > 0)
                ans[c++]= 32;  // add a space char after a word
        }
        else        // ignore spaces
            i--;
    }
      
    for(i=0 ; i < c-1; i++)
        s[i]= ans[i];
    s[i]='\0';  // terminate the string
}



void main(){
    // char A[] = "the sky is blue";
    // char A = "this is ib";
    // char A[] = " hello world ";
    char A[] = "       fwbpudnbrozzifml osdt ulc jsx kxorifrhubk ouhsuhf sswz qfho dqmy sn myq igjgip iwfcqq                 ";

    // char reversed;
    printf("%s!\n", A);

    solve(A);
    printf("%s*\n", A);

    // reverseWords(&A);
    // printf("%s*\n", A);

    printf("\n\n");

    return;
}