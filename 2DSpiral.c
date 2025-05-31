#include <stdio.h>


void main(){
    // variables
    int size;     
    int length;   
    int x, y;
    int counter;
    int i, j;
    int x_size, y_size;

    printf("size? ");
    scanf("%d", &size);
    int array[size][size];
    
    // initialize variables
    i = 0;          // starting point for iterating on x
    j = 1;          // starting point for iterating on y
    length = size*size; // total number of places to be populated
    counter = 0;        
    x_size = size;      // aux variable to remember the full size of the matrix
    y_size = size;      // aux variable to remember the full size of the matrix

    do {
        for (x = i; x < size; x++){         // populate ->
            array[x][y] = counter; 
            counter++;            
        }
        x--;    // adjust starter x
        for (y = j; y < size; y++){         // populate v
            array[x][y] = counter;
            counter++;
        }
        y--;    // adjust starter y
        for (x = x-1; x >= i; x--){         // populate <-
            array[x][y] = counter; 
            counter++;
        }
        x++;   // adjust starter x
        for (y = y-1; y >= j; y--){         // populate ^
            array[x][y] = counter; 
            counter++;
        }
        y++;    // adjust starter y
        
        i++;    // move to internal square
        j++;
        size--; // work with smaller square
   } while (counter < length);  // repeat as necessary


    // print result matrix
    for (int i = 0; i < y_size; i++){
        for (int j = 0; j < x_size; j++){
            printf("%03d ", array[j][i]);
        }
        printf("\n");
    }

    printf("\n");
}