/*********************** 
Problem Description
Given a read-only array of n + 1 integers between 1 and n, find one number that repeats in linear time using 
less than O(n) space and traversing the stream sequentially O(1) times.
If there are multiple possible answers ( like in the sample case ), output any one, if there is no duplicate, output -1


Problem Constraints
1 <= |A| <= 105
1 <= Ai <= |A|


Input Format
The first argument is an integer array A.


Output Format
Return the integer that repeats in array A


Example Input
Input 1:
A = [3, 4, 1, 4, 2]
Input 2:
A = [1, 2, 3]
Input 3:
A = [3, 4, 1, 4, 1]


Example Output
Output 1:
4
Output 2:
-1
Output 3:
1


Example Explanation
Explanation 1:
4 repeats itself in the array [3, 4, 1, 4, 2]
Explanation 2:
No number repeats itself in the array [1, 2, 3]
Explanation 3:
1 and 4 repeats itself in the array [3, 4, 1, 4, 1], we can return 1 or 4


************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>


// int repeatedNumber(const int* A, int n1) {
//     // int i;
//     // int counter[n1];

//     // if (n1 < 1){
//     //     return -1;
//     // }

//     // for (i = 0; i < n1; i++){
//     //     counter[A[i]]++;
//     //     if (counter[A[i]] > 1){
//     //         return A[i];
//     //     }
//     // }

//     // return -1; 

//     //////////////////////////////
//     // int i, j;
//     // int ret = -1;

//     // if (n1 < 1)
//     //     return ret;
    

//     // for (i = 0; i < n1-1; i++){
//     //     for (j = i+1; j < n1; j++){
//     //         printf("testing A[%d] = %d versus A[%d] = %d\n", i, A[i], j, A[j]);
//     //         if (A[j] == A[i]){
//     //             ret = A[i];
//     //             printf("A[%d] = %d and A[%d] = %d are duplicate!\n", i, A[i], j, A[j]);
//     //             return ret;
//     //         }
//     //     }
//     // }

//     // return ret; 
// ////////////////////////////////////////////

// ////////////////////////////////////////////
//     // int slow = A[0], fast = A[0];
//     // printf("slow = %d\n", slow);
//     // printf("fast = %d\n\n", fast);

//     // if (n1 == 1){
//     //     return -1;
//     // }
    
//     // // Step 1: Detect cycle using Floyd's algorithm
//     // do {
//     //     printf("slow = A[slow] = A[%d] = %d\n", slow, A[slow]);
//     //     // printf("A[fast] = A[%d] = %d\n", fast, A[fast]);
//     //     printf("fast = A[A[fast]] = A[A[%d]] = A[%d]= %d\n\n", fast, A[fast], A[A[fast]]);
        
//     //     slow = A[slow];
//     //     fast = A[A[fast]];
//     // } while (slow != fast);
//     // printf("step 1 done!\n\n");

//     // // Step 2: Find the entrance to the cycle (duplicate number)
//     // slow = A[0];
//     // while (slow != fast) {
//     //     printf("slow = A[slow] = A[%d] = %d\n", slow, A[slow]);
//     //     printf("fast = A[fast] = A[%d] = %d\n", fast, A[fast]);
        
//     //     slow = A[slow];
//     //     fast = A[fast];
//     // }
    
//     // return slow;
// ////////////////////////////////////////////////
//     int i;
//     if (n1 <= 1) return -1;  // No duplicates possible

//     int bucketSize = (int)sqrt(n1);
//     if (bucketSize < 1) bucketSize = 1;  // Prevent division by zero

//     int numBuckets = (n1 + bucketSize - 1) / bucketSize; // Equivalent to ceil(N / bucketSize)

//     int *bucketCounts = (int*)calloc(numBuckets, sizeof(int));
//     if (!bucketCounts) return -1;  // Check memory allocation failure

//     // Step 1: Count elements in each bucket
//     for (i = 0; i < n1; i++) {
//         if (A[i] < 1 || A[i] > n1) {
//             free(bucketCounts);
//             return -1;  // Invalid input number
//         }
//         int bucketIndex = (A[i] - 1) / bucketSize;
//         if (bucketIndex < numBuckets) {
//             bucketCounts[bucketIndex]++;
//         }
//     }

//     // Step 2: Identify overloaded bucket
//     int targetBucket = -1;
//     for (i = 0; i < numBuckets; i++) {
//         if (bucketCounts[i] > bucketSize) {
//             targetBucket = i;
//             break;
//         }
//     }

//     free(bucketCounts);

//     if (targetBucket == -1) return -1;  // No duplicates found

//     // Step 3: Find duplicate within overloaded bucket
//     int *temp = (int*)calloc(bucketSize, sizeof(int));
//     if (!temp) return -1;  // Check memory allocation failure

//     int rangeStart = targetBucket * bucketSize + 1;
//     int rangeEnd = rangeStart + bucketSize;

//     for (i = 0; i < n1; i++) {
//         if (A[i] >= rangeStart && A[i] < rangeEnd) {
//             int index = A[i] - rangeStart;
//             if (temp[index] == 1) {
//                 free(temp);
//                 return A[i];  // Found duplicate
//             }
//             temp[index] = 1;
//         }
//     }

//     free(temp);
//     return -1;  // No duplicate found
// }


int findDuplicate(int A[], int N) {
    printf("Starting function with N=%d\n", N);
    
    if (N <= 1) return -1;  // Handle edge case safely
    
    int bucketSize = (int)sqrt(N);
    printf("bucketSize = %d\n", bucketSize);
    
    if (bucketSize == 0) bucketSize = 1; // Prevent division by zero

    int numBuckets = (N + bucketSize - 1) / bucketSize;
    printf("numBuckets = %d\n", numBuckets);

    int* bucketCounts = (int*)calloc(numBuckets, sizeof(int));
    if (!bucketCounts) {
        printf("Memory allocation failed for bucketCounts\n");
        return -1;
    }

    for (int i = 0; i < N; i++) {
        int bucketIndex = (A[i] - 1) / bucketSize;
        printf("Processing A[%d] = %d -> bucketIndex = %d\n", i, A[i], bucketIndex);
        if (bucketIndex < 0 || bucketIndex >= numBuckets) {
            printf("ERROR: bucketIndex %d is out of bounds\n", bucketIndex);
            free(bucketCounts);
            return -1;
        }
        bucketCounts[bucketIndex]++;
    }

    int targetBucket = -1;
    for (int i = 0; i < numBuckets; i++) {
        if (bucketCounts[i] > bucketSize) {
            targetBucket = i;
            break;
        }
    }
    free(bucketCounts);

    if (targetBucket == -1) {
        printf("No duplicate found!\n");
        return -1;
    }

    int* temp = (int*)calloc(bucketSize, sizeof(int));
    if (!temp) {
        printf("Memory allocation failed for temp\n");
        return -1;
    }

    int start = targetBucket * bucketSize + 1;
    int end = (targetBucket + 1) * bucketSize;
    printf("Searching in bucket range: [%d, %d]\n", start, end);

    for (int i = 0; i < N; i++) {
        if (A[i] >= start && A[i] <= end) {
            int index = A[i] - start;
            printf("Checking A[%d] = %d -> temp[%d]\n", i, A[i], index);
            if (temp[index] == 1) {
                free(temp);
                printf("Duplicate found: %d\n", A[i]);
                return A[i];
            }
            temp[index] = 1;
        }
    }

    free(temp);
    return -1;
}


int main() {
    // int A[5] = {1, 2, 2, 7, 1};
    // int A[5] = {3, 4, 1, 4, 2};
    // int A[3] = {1, 2, 3};
    // int A[5] = {3, 4, 1, 4, 1};
    // int A[6] = {1, 4, 3, 5, 2, 2};
    // int A[360] = {247, 240, 303, 9, 304, 105, 44, 204, 291, 26, 242, 2, 358, 264, 176, 289, 196, 329, 189, 102, 45, 111, 115, 339, 74, 200, 34, 201, 215, 173, 107, 141, 71, 125, 6, 241, 275, 88, 91, 58, 171, 346, 219, 238, 246, 10, 118, 163, 287, 179, 123, 348, 283, 313, 226, 324, 203, 323, 28, 251, 69, 311, 330, 316, 320, 312, 50, 157, 342, 12, 253, 180, 112, 90, 16, 288, 213, 273, 57, 243, 42, 168, 55, 144, 131, 38, 317, 194, 355, 254, 202, 351, 62, 80, 134, 321, 31, 127, 232, 67, 22, 124, 271, 231, 162, 172, 52, 228, 87, 174, 307, 36, 148, 302, 198, 24, 338, 276, 327, 150, 110, 188, 309, 354, 190, 265, 3, 108, 218, 164, 145, 285, 99, 60, 286, 103, 119, 29, 75, 212, 290, 301, 151, 17, 147, 94, 138, 272, 279, 222, 315, 116, 262, 1, 334, 41, 54, 208, 139, 332, 89, 18, 233, 268, 7, 214, 20, 46, 326, 298, 101, 47, 236, 216, 359, 161, 350, 5, 49, 122, 345, 269, 73, 76, 221, 280, 322, 149, 318, 135, 234, 82, 120, 335, 98, 274, 182, 129, 106, 248, 64, 121, 258, 113, 349, 167, 192, 356, 51, 166, 77, 297, 39, 305, 260, 14, 63, 165, 85, 224, 19, 27, 177, 344, 33, 259, 292, 100, 43, 314, 170, 97, 4, 78, 310, 61, 328, 199, 255, 159, 185, 261, 229, 11, 295, 353, 186, 325, 79, 142, 223, 211, 152, 266, 48, 347, 21, 169, 65, 140, 83, 156, 340, 56, 220, 130, 117, 143, 277, 235, 59, 205, 153, 352, 300, 114, 84, 183, 333, 230, 197, 336, 244, 195, 37, 23, 206, 86, 15, 187, 181, 308, 109, 293, 128, 66, 270, 209, 158, 32, 25, 227, 191, 35, 40, 13, 175, 146, 299, 207, 217, 281, 30, 357, 184, 133, 245, 284, 343, 53, 210, 306, 136, 132, 239, 155, 73, 193, 278, 257, 126, 331, 294, 250, 252, 263, 92, 267, 282, 72, 95, 337, 154, 319, 341, 70, 81, 68, 160, 8, 249, 96, 104, 137, 256, 93, 178, 296, 225, 237};
    // int A[2] = {1, 1};
    // int A[1] = {1};
    int A[10] = {1, 2, 8, 4, 5, 6, 7, 9, 9};
    int number;
  
    int totalSize = sizeof(A);
    int elementSize = sizeof(A[0]);
    int n1 = totalSize / elementSize;
  
    number = findDuplicate((int*)&A, n1);
  
    printf("\nrepeated number: %d\n\n\n\n\n\n", number);
  }