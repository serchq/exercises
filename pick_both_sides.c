/*   
////////////////////////////////////////////////////////////
////                                                    ////
////                    SLIDING WINDOW                  ////
////                                                    ////
////////////////////////////////////////////////////////////

Given an integer array A of size N.

You have to pick exactly B elements from either left or right end of the array A to get the maximum sum.
Find and return this maximum possible sum.

NOTE: Suppose B = 4 and array A contains 10 elements then You can pick the first four elements or can pick 
the last four elements or can pick 1 from the front and 3 from the back etc. 

you need to return the maximum possible sum of elements you can pick.


Problem Constraints
1 <= N <= 105
1 <= B <= N
-103 <= A[i] <= 103


Input Format
First argument is an integer array A.
Second argument is an integer B.

Output Format
Return an integer denoting the maximum possible sum of elements you picked.


Example Input
Input 1:

 A = [5, -2, 3 , 1, 2]
 B = 3
Input 2:

 A = [1, 2]
 B = 1


Example Output
Output 1:

 8
Output 2:

 2

Example Explanation
Explanation 1:

 Pick element 5 from front and element (1, 2) from back so we get 5 + 1 + 2 = 8
Explanation 2:

 Pick element 2 from end as this is the maximum we can get

*/


/**
 * @input A : Integer array
 * @input n1 : Integer array's ( A ) length
 * @input B : Integer
 * 
 * @Output Integer
 */

#include <stdio.h>
#include <stdlib.h>

int solve(int* A, int n1, int B) {
    int i; 
    int left_sum = 0;
    int max_sum = 0;
    int right_sum = 0;
    int sum; 

    printf("elements: [ ");
    for (i = 0; i < B; i++){
        left_sum += A[i];
        printf("%d ", A[i]);
    }
    printf("]\n");

    max_sum = left_sum;

    printf("right side: [ ");
    for (i = 0; i < B; i++){
        left_sum -= A[B - 1 - i];  // remove last element of left window
        right_sum += A[n1 - 1 - i]; // add element from the right end
        printf("%d ", A[n1 - 1 - i]);

        sum = left_sum + right_sum;
        if (sum > max_sum){
            max_sum = sum;
        }
    }
    printf("]\n");


    return max_sum;

}




void main(){
    // int A[5] = {5, -2, 3 , 1, 2};
    // int B = 3;

    int A[61] = {-533,-666,-500,169,724,478,358,-38,-536,705,-855,281,-173,961,-509,-5,942,-173,436,-609,-396,902,-847,-708,-618,421,-284,718,895,447,726,-229,538,869,912,667,-701,35,894,-297,811,322,-667,673,-336,141,711,-747,-132,547,644,-338,-243,-963,-141,-277,741,529,-222,-684,35};
    int B = 48;
    


    int totalSize = sizeof(A);
    int elementSize = sizeof(int);
    int n1 = totalSize / elementSize;

    int max_sum;

    max_sum = solve(A, n1, B);

    printf("max sum = %d", max_sum);


    printf("\n\n\n\n");
}


