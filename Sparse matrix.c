#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	
	    int mat[3][3] = {
        {  1, 3, 5},
        {6, 8, 9},
        {4, 2, 4}
    };

    int sparse[10][3];
    int i, j, k = 1;
    int rows = 3, cols = 3;
    int count = 0;

    // Count non-zero elements
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mat[i][j] != 0)
                count++;
        }
    }

    // First row of sparse matrix
    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = count;

    // Convert to sparse form
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (mat[i][j] != 0) {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = mat[i][j];
                k++;
            }
        }
    }

    // Print sparse matrix
    printf("Sparse Matrix (Row Col Value):\n");
    for (i = 0; i <= count; i++) {
        printf("%d %d %d\n",
               sparse[i][0],
               sparse[i][1],
               sparse[i][2]);
    }
	return 0;
}
