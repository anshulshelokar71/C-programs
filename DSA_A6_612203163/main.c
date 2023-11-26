#include "List.c"
#include<stdio.h>
#include<stdlib.h>

int main() {
    Node* A = NULL;
    Node* B = NULL;
    init(&A);
    sparseMatrix("Matrix1.txt", &A);
    init(&B);
    sparseMatrix("Matrix2.txt", &B);
    display(&A, 4, 3);
    printf("\n");
    display(&B, 4, 3);
    printf("\n");    
    
    Node* result1 = add(A, B);
    printf("Addition Matrix:\n");
    display(&result1, 4, 3);
    save_to_file("MatrixSum.txt", result1, 4, 3);
    printf("\n");
    
    Node* result2 = sub(A, B);
    printf("Subtraction Matrix:\n");
    display(&result2, 4, 3);
    save_to_file("MatrixDiff.txt", result2, 4, 3);

    
    return 0;
}
