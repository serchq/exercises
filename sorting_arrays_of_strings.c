/*
To sort a given array of strings into lexicographically increasing order or into an order in which the string with the 
lowest length appears first, a sorting function with a flag indicating the type of comparison strategy can be written. 
The disadvantage with doing so is having to rewrite the function for every new comparison strategy.

A better implementation would be to write a sorting function that accepts a pointer to the function that compares each pair 
of strings. Doing this will mean only passing a pointer to the sorting function with every new comparison strategy.

Given an array of strings, you need to implement a string_sort function which sorts the strings according to a comparison 
function, i.e, you need to implement the function :

void string_sort(const char **arr,const int count, int (*cmp_func)(const char* a, const char* b)){
}

The arguments passed to this function are:
    an array of strings : arr
    length of string array: count
    pointer to the string comparison function: cmp_func

You also need to implement the following four string comparison functions:
    1. int lexicographic_sort(char*, char*) to sort the strings in lexicographically non-decreasing order.
    2. int lexicographic_sort_reverse(char*, char*) to sort the strings in lexicographically non-increasing order.
    3. int sort_by_number_of_distinct_characteres(char*, char*) to sort the strings in non-decreasing order of the 
       number of distinct characters present in them. If two strings have the same number of distinct characters 
       present in them, then the lexicographically smaller string should appear first.
    4. int sort_by_length)(char*, char*) to sort the strings in non-decreasing order of their lengths. If two strings 
       have the same length, then the lexicographically smaller string should appear first.

Input Format
You just need to complete the function string\_sort and implement the four string comparison functions.

Constraints
    1 <= No. of Strings <= 50
    1 <= Total Length of all the strings <= 2500
    You have to write your own sorting function and you cannot use the inbuilt qsort function
    The strings consists of lower-case English Alphabets only.

Output Format

The locked code-stub will check the logic of your code. The output consists of the strings sorted according to the four 
comparsion functions in the order mentioned in the problem statement.

Sample Input 0
4
wkue
qoi
sbv
fekls

Sample Output 0
fekls
qoi
sbv
wkue

wkue
sbv
qoi
fekls

qoi
sbv
wkue
fekls

qoi
sbv
wkue
fekls
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* sort the strings in lexicographically non-decreasing order. */
int lexicographic_sort(const char* a, const char* b) {
    int i = 0;
    while ((a[i] != '\0') || (b[i] != '\0')){
        if (a[i] < b[i]){
            return 1; 
        } else if (a[i] > b[i]){
            return 0;
        }
        i++;
    }
    if (strlen(a) > strlen(b)){
        return 0;
    }
}

/* sort the strings in lexicographically non-increasing order. */
int lexicographic_sort_reverse(const char* a, const char* b) {
    int i = 0;
    while ((a[i] != '\0') || (b[i] != '\0')){
        if (a[i] < b[i]){
            return 0; 
        } else if (a[i] > b[i]){
            return 1;
        }
        i++;
    }
    if (strlen(a) > strlen(b)){
        return 1;
    }
}

/* sort the strings in non-decreasing order of the number of distinct characters present in them. 
   If two strings have the same number of distinct characters present in them, then the lexicographically 
   smaller string should appear first.*/

int distinct_characters(const char* str){
    int* alphabet = (int*)calloc(26, sizeof(int));  // one int for each letter of the alphabet.
    int distinct = 0; 
    
    for (int i = 0; i < strlen(str); i++){
        if (alphabet[str[i] - 97]++ == 0){    // reduce 97d to make 'a' = 0, 'b' = 1, and so on. 
            distinct++;        
        }  
                  
    }
    free(alphabet);
    return distinct;    
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int distinct_a = distinct_characters(a);
    int distinct_b = distinct_characters(b);
    
    if (distinct_a < distinct_b){
        return 1;
    } else if (distinct_a > distinct_b){
        return 0;
    } else {
        return lexicographic_sort(a, b);
    }
    return 0;
}

/* sort the strings in non-decreasing order of their lengths. If two strings have the same length, 
   then the lexicographically smaller string should appear first.*/
int sort_by_length(const char* a, const char* b) {
    int i = 0;
    if (strlen(a) == strlen(b)){
        while (i < strlen(a)){
            if (a[i] < b[i]){
                return 1; 
            } else if (a[i] > b[i]){
                return 0;
            }
            i++;
        }
    } else if (strlen(a) > strlen(b)){
        return 0;
    } else
        return 1;
}

void merge(char** arr, char** left, int leftSize, char** right, int rigthSize, int (*cmp_func)(const char*, const char* b)){
    int i = 0, j = 0, k = 0;

    // merge in order
    while (i < leftSize && j < rigthSize){
        if (cmp_func(left[i], right[j])){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    // copy remaining elements
    while (i < leftSize)
        arr[k++] = left[i++];

    while (j < rigthSize)
        arr[k++] = right[j++];

}


void string_sort(char** arr, const int len, int (*cmp_func)(const char* a, const char* b)){
    if (len <= 1){
        return;
    }
    
    int mid = len/2;
    char** left = (char**)malloc(mid * sizeof(char*));
    char** right = (char**)malloc((len - mid) * sizeof(char*));

    // separate array in half
    for (int i = 0; i < mid; i++){
        left[i] = arr[i];
    }
    for (int i = mid; i < len; i++){
        right[i - mid] = arr[i];
    }

    // recursively split array again until there's 1 element per array
    string_sort(left, mid, cmp_func);
    string_sort(right, len - mid, cmp_func);

    merge(arr, left, mid, right, len - mid, cmp_func);

    free(left);
    free(right);
}

int main() 
{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    printf("\n");

    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}

