#include"List.h"

void init(Node **head){
    *head = NULL;
}

void append(Node**head, int row ,int column, int data){
    Node*nn = (Node*)malloc(sizeof(Node));
    if(nn == NULL){
        return;
    }else{
        nn->row = row;
        nn->column = column;
        nn->data = data;
        nn->next = NULL;
    }
    if(*head == NULL){
        *head = nn;
        return;
    }
    Node* n = *head;
    while(n->next!=NULL){
        n = n->next;
    }
    n->next = nn;
}

void sparseMatrix(const char* filename, Node**p){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Failed to open the file.\n");
        return;
    }
    int rows, columns;
    fscanf(file, "%d %d", &rows, &columns);

    int data;
    for(int i = 0; i < rows;i++){
        for(int j = 0; j < columns; j++){
            fscanf(file, "%d",&data);
            if(data != 0){
                append(p, i, j, data);
            }
        }
    }
    fclose(file);
}

Node* add(Node*n1,Node*n2){
    Node* result = NULL;
     while (n1 != NULL && n2 != NULL) {
        if (n1->row == n2->row && n1->column == n2->column) {
            int sum = n1->data + n2->data;
            if (sum != 0) {
                append(&result, n1->row, n2->column, sum);
            }
            n1 = n1->next;
            n2 = n2->next;
        } else if ((n1->row < n2->row) || (n1->row == n2->row && n1->column < n2->column)) {
            append(&result, n1->row, n1->column, n1->data);
            n1 = n1->next;
        } else {
            append(&result, n2->row, n2->column, n2->data);
            n2 = n2->next;
        }
    }

     while (n1 != NULL) {
        append(&result, n1->row, n1->column, n1->data);
        n1 = n1->next;
    }

    while (n2 != NULL) {
        append(&result, n2->row, n2->column, n2->data);
        n2 = n2->next;
    }

    return result;

}

Node* sub(Node* n1, Node* n2) {
    Node* result = NULL;

    while (n1 != NULL && n2 != NULL) {
        if (n1->row == n2->row && n1->column == n2->column) {
            int sub = n1->data - n2->data;
            if (sub != 0) {
                append(&result, n1->row, n2->column, sub);
            }
            n1 = n1->next;
            n2 = n2->next;
        } else if ((n1->row < n2->row) || (n1->row == n2->row && n1->column < n2->column)) {
            append(&result, n1->row, n1->column, n1->data);
            n1 = n1->next;
        } else {
            append(&result, n2->row, n2->column, -(n2->data));
            n2 = n2->next;
        }
    }

    while (n1 != NULL) {
        append(&result, n1->row, n1->column, n1->data);
        n1 = n1->next;
    }

    while (n2 != NULL) {
        append(&result, n2->row, n2->column, -(n2->data));
        n2 = n2->next;
    }

    return result;
}

void display(Node** head, int rows, int columns) {
    Node* p = *head;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (p != NULL && p->row == i && p->column == j) {
                printf("%d ", p->data);
                p = p->next;
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

void save_to_file(const char* filename, Node* result, int rows, int columns) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("Failed to open the file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "%d %d\n", rows, columns);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            if (result != NULL && result->row == i && result->column == j) {
                fprintf(file, "%d ", result->data);
                result = result->next;
            } else {
                fprintf(file, "0 ");
            }
        }
        fprintf(file, "\n");
    }

    fclose(file);
}
