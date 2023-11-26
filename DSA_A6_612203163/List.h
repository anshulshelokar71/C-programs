#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int row;
    int column;
    int data;
    struct Node *next;
} Node;

void init(Node **n);
void append(Node **n, int a, int b, int c);
void sparseMatrix(const char *filename, Node **n);
void display(Node **head, int rows, int columns);
void save_to_file(const char *filename, Node *result, int rows, int columns);
Node *add(Node *n1, Node *n2);
Node *sub(Node *n1, Node *n2);
