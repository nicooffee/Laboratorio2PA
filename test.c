#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main(){
    int *A;
    int i;
    Matrix M = matrix_create(5,4);
    matrix_print(M);
    matrix_print(matrix_transpose(M));
    A = matrix_toArray(M);
    for(i;i<matrix_lenRow(M)*matrix_lenCol(M);i++)
        printf("%d ",A[i]);
    matrix_free(M);
}