/*
You are given n triangles, specifically, their sides ai, bi and ci. Print them 
in the same style but sorted by their areas from the smallest one to the largest 
one. It is guaranteed that all the areas are different.

The best way to calculate a area of a triangle with sides a, b and c is Heron's 
formula:
    S = Sqrt(p x (p-a) x (p-b) x (p-c))
 where 
    p = (a+b+c)/2
 .

Input Format

The first line of each test file contains a single integer n. n lines follow with three 
space-separated integers, ai, bi and ci.

Constraints
- 1 <= n <= 100
- 1 <= ai, bi, ci <= 70
- ai + bi > ci. ai + ci > bi. bi + ci > ai 

Output Format
Print exactly n lines. On each line print 3 space-separated integers, the ai, bi and ci of 
the corresponding triangle.

Sample Input 0

3
7 24 25
5 12 13
3 4 5

Sample Output 0

3 4 5
5 12 13
7 24 25

Explanation 0

The area of the first triangle is . The area of the second triangle is . The area of the third triangle is . So the sorted order is the reverse one.
*/

// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>

// struct triangle
// {
// 	int a;
// 	int b;
// 	int c;
// };

// typedef struct triangle triangle;

// double calcArea(triangle* tr){
//     double area;
//     double p;
    
//     p = (tr->a + tr->b + tr->c)/2;
//     // printf("semi perimeter: %f\n", p);
//     area = sqrt(p * (p - tr->a) * (p - tr->b) * (p - tr->c));
//     // printf("area: %f\n", area);
    
//     return area;
// }


// void sort_by_area(triangle* tr, int n) {
// 	/**
// 	* Sort an array a of the length n
// 	*/    
//     for (int i = 0; i < n; i++){
//         printf("triangle area: %f\n", calcArea(&tr[i]));
//     }
    
    
    
// }

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Structure to store triangle sides and area
typedef struct {
    int a, b, c;
} Triangle;

// Function to calculate the area using Heron's formula
double calculate_area(Triangle* tr) {
    double p = (tr->a + tr->b + tr->c) / 2.0;
    return sqrt(p * (p - tr->a) * (p - tr->b) * (p - tr->c));
}

// Merge function for Merge Sort
void merge(Triangle arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    Triangle *L = (Triangle*)malloc(n1 * sizeof(Triangle));
    Triangle *R = (Triangle*)malloc(n2 * sizeof(Triangle));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0; 
    j = 0; 
    k = left; 
    while (i < n1 && j < n2) {
        if (calculate_area(&L[i]) <= calculate_area(&R[j])) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    // Free allocated memory
    free(L);
    free(R);
}

// Merge Sort function
void merge_sort(Triangle arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}




int main()
{
	int n = 3;
    // Triangle *tr = malloc(n * sizeof(Triangle));
    Triangle tr[n];
    tr[0].a = 7; tr[0].b = 24; tr[0].c = 25;
    tr[1].a = 5; tr[1].b = 12; tr[1].c = 13;
    tr[2].a = 3; tr[2].b = 4; tr[2].c = 5;


    for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
    printf("\n\n");

       merge_sort(tr, 0, n - 1);
	
    for (int i = 0; i < n; i++) {
		printf("%d %d %d\n", tr[i].a, tr[i].b, tr[i].c);
	}
	return 0;
}



    // scanf("%d", &n);
	// triangle *tr = malloc(n * sizeof(triangle));
	// for (int i = 0; i < n; i++) {
	// 	scanf("%d%d%d", &tr[i].a, &tr[i].b, &tr[i].c);
	// }
	// sort_by_area(tr, n);
       // Sort triangles based on area