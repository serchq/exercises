#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGIT 10 // Digits range from 0-9

// Function to extract the first and last digit of a number
void extract_digits(int num, int *first, int *last) {
    num = abs(num); // Ensure positive values for extraction
    *last = num % 10;
    while (num >= 10) {
        num /= 10;
    }
    *first = num;
}

// Optimized function to count valid pairs using a frequency table
int count_valid_pairs(int arr[], int N) {
    int freq[MAX_DIGIT][MAX_DIGIT] = {0}; // Frequency table for (first, last) pairs
    int count = 0;

    // Populate the frequency table
    for (int i = 0; i < N; i++) {
        int first, last;
        extract_digits(arr[i], &first, &last);
        freq[first][last]++;
        // printf("freq[first][last] = freq[%d][%d] =%d\n", first, last, freq[first][last]);
    }

    // Compute the valid pairs
    for (int first = 0; first < MAX_DIGIT; first++) {
        for (int last = 0; last < MAX_DIGIT; last++) {
            if (freq[first][last] > 0) {
                // Count pairs where the last digit matches another's first digit
                for (int next_first = 0; next_first < MAX_DIGIT; next_first++) {
                    // printf("if (freq[last][next_first] > 0) = if (freq[%d][%d] > 0) = if (%d > 0)\n",last, next_first, freq[last][next_first]);
                    if (freq[last][next_first] > 0) {
                        count += freq[first][last] * freq[last][next_first];
                        // printf("count += freq[first][last] * freq[last][next_first] = freq[%d][%d] * freq[%d][%d]\n", first, last, last, next_first);
                    }
                }
            }
        }
    }
    
    return count;
}

int main() {
    int arr1[] = {30, 21, 19, 91};
    int arr2[] = {122, 21, 21, 23, 48};
    int arr3[] = {-12, -21, 34, -43, 56};
    
    printf("%d\n", count_valid_pairs(arr1, 4)); // Output: 2
    printf("%d\n", count_valid_pairs(arr2, 5)); // Output: 5
    printf("%d\n", count_valid_pairs(arr3, 5)); // Output should be correct even for negatives
    
    return 0;
}
