/*
The problem involves finding all possible indices where removing a character from str1 would make it equal to str2. For example:
*   If str1 = "abccd" and str2 = "abcd", the answer would be [2, 3] because removing either 'c' would make the strings equal.

Problem Statement
Given two strings, str1, and str2, where str1 contains exactly one character more than str2, find the indices of the characters 
in str1 that can be removed to make str1 equal to str2. Return the array of indices in increasing order. If it is not possible, 
return the array [-1]. 

Note: Use 0-based indexing.

Example

str1 = "abdgggda"

str2 = "abdggda"

Any "g" character at positions 3, 4, or 5 can be deleted to obtain str2. Return [3, 4, 5].

Input Format
getRemovableIndices() has the following parameters:

string str1: the string to modify
string str2: the target string

Output Format
int[]: the indices of characters that can be removed from str1 in ascending order, or [-1] if it is not possible to match str2

Constraints
* 2 ≤ |str1| ≤ 2 \* 10^5  
* 1 ≤ |str2| ≤ 2 \* 10^5  
* |str1| = |str2| + 1   
* str1 and str2 only contain lowercase English letters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


// int* getRemovableIndices(char* str1, char* str2, int* result_count) {
//     int len1 = strlen(str1);
//     int len2 = strlen(str2);
//     int *candidates = (int*)calloc(strlen(str1), sizeof(int));
//     int index = 0;
//     *result_count = 0;
//     int equal = 1;

//     for (int i = 0; i < len1; i++){
//         // printf("current candidate to be removed:\n\tstr1[%d] = %c\n", i, str1[i]);
//         // printf("comparing: \n");
//         int k = 0;
//         for (int j = 0; j < len2; j++){
//             if (k == i) k++;            
//             // printf("str1[%d] <=> str2[%d] | %c <=> %c\n", k, j, str1[k], str2[j]);
//             if (str1[k] != str2[j]){    
//                 equal = 0;
//                 break;
//             }
//             equal = 1;           
//             k++;
//         }
        
//         if (equal){
//             // printf("strings are equal\nsaving index %d\n", i);
//             candidates[index] = i;       // if strings are equal when removing the candidate, store the index of it
//             index++;
//             // printf("candidates: [");
//             // for (int temp = 0; temp < index; temp++){
//             //     printf("%i ", candidates[temp]);
//             // }
//             // printf("]\n\n");

//         // } else {
//             // printf("strings are different. resetting...\n\n");
//             // index = 0;                       // otherwise, restart the array;
//             // candidates[index] = 0;
//         }
//     }

//     if (index == 0){
//         candidates[0] = -1;
//         index = 1;
//     }
//     *result_count = index;
//     // printf("result_count = %d\n", *result_count);
//     return candidates;
// }

int* getRemovableIndices(char* str1, char* str2, int* result_count) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int *candidates = (int*)calloc(strlen(str1), sizeof(int));
    int index = 0;
    *result_count = 0;


    for (int i = 0; i < len1; i++){
        int p1 = 0, p2 = 0;         // two pointers approach
        
        while (p1 < len1){
            if (p1 == i){       // skip the current character
                p1++;
                continue;
            }
            if (str1[p1] != str2[p2]){  // there's a mismatch. this char can't be removed
                break;                      
            }
            p1++;
            p2++;
        }

        if (p2 == len2)             // if the string was read completely, store the index for the removed char
            candidates[index++] = i;
    }

    
    if (index == 0){  // if no valid index found, return -1
        candidates[0] = -1;
        index = 1;
    }
    *result_count = index;
    // printf("result_count = %d\n", *result_count);
    return candidates;
}




int main(){
    // char* str1 = "aabbbb";
    // char* str2 = "aabbb";

    char* str1 = "abdgggda";
    char* str2 = "abdggda";

    int result_count;
    int* result = getRemovableIndices(str1, str2, &result_count);

    printf("result_count = %d\n", result_count);
    for (int i = 0; i < result_count; i++) {
        printf("%d", *(result + i));
        if (i != result_count - 1) {
            printf("\n");
        }
    }
    printf("\n");

    free(result);
    return 0;

}
