#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char *name;
    struct Node *right, *left, *parent;
    int balance_factor;
} Node;

typedef Node *AVL;

void init(AVL *root) {
    *root = NULL;
}

int height(AVL root) {
    if (root == NULL) {
        return -1; 
    } else {
        int height_lst = height(root->left);
        int height_rst = height(root->right);
        return (height_lst > height_rst ? height_lst : height_rst) + 1;
    }
}

void adjustbalance_factor(AVL *t) {
    Node *p = *t;
    while (p) {
        p->balance_factor = height(p->left) - height(p->right);
        p = p->parent;
    }
}


AVL createNode(char *name) {
    Node *nn = (Node *)malloc(sizeof(Node));
    nn->name = (char *)malloc(strlen(name) + 1);
    strcpy(nn->name, name);
    nn->right = NULL;
    nn->left = NULL;
    nn->parent = NULL;
    nn->balance_factor = 0;
    return nn;
}

void RR(AVL *t, Node *n) {
    Node *temp = n->right;
    n->right = temp->left;
    if (n->right) {
        n->right->parent = n;
    }
    temp->left = n;
    temp->parent = n->parent;
    n->parent = temp;
    if (temp->parent) {
        if (temp->parent->left == n) {
            temp->parent->left = temp;
        } else {
            temp->parent->right = temp;
        }
    } else {
        *t = temp;
    }
    adjustbalance_factor(&n);
    adjustbalance_factor(&temp);
}

void LL(AVL *t, Node *n) {
    Node *temp = n->left;
    n->left = temp->right;
    if (n->left) {
        n->left->parent = n;
    }
    temp->right = n;
    temp->parent = n->parent;
    n->parent = temp;
    if (temp->parent) {
        if (temp->parent->left == n) {
            temp->parent->left = temp;
        } else {
            temp->parent->right = temp;
        }
    } else {
        *t = temp;
    }
    adjustbalance_factor(&n);
    adjustbalance_factor(&temp);
}

void RL(AVL *t, Node *n) {
    RR(t, n->left);
    LL(t, n);
}

void LR(AVL *t, Node *n) {
    LL(t, n->right);
    RR(t, n);
}

void adjustImbalance(AVL *t, Node *n) {
    while (n) {
        n->balance_factor = height(n->left) - height(n->right);
        if (n->balance_factor < -1) {
            if (n->right->balance_factor <= 0) {
                RR(t, n);
            } else {
                LR(t, n);
            }

        } else if (n->balance_factor > 1) {
            if (n->left->balance_factor >= 0) {
                LL(t, n);
            } else {
                RL(t, n);
            }
        }
        n = n->parent;
    }
}

void insert(AVL *t, char *name) {
    Node *nn = createNode(name);
    if (*t == NULL) {
        *t = nn;
        return;
    }
    Node *p = *t;
    Node *prev = NULL;
    while (p) {
        prev = p;
        if (strcmp(name, p->name) < 0) {
            p = p->left;
        } else if (strcmp(name, p->name) > 0) {
            p = p->right;
        } else {
            return;
        }
    }
    if (strcmp(name, prev->name) < 0) {
        prev->left = nn;
    } else {
        prev->right = nn;
    }
    nn->parent = prev;
    adjustbalance_factor(&nn);
    adjustImbalance(t, nn->parent);
}

void preorder(AVL n) {
    if (n) {
        if (n->parent) {
            printf("[%s balance_factor: %d Parent: %s ]\n", n->name, n->balance_factor, n->parent->name);
        } else {
            printf("[%s balance_factor: %d [Root] ]\n", n->name, n->balance_factor);
        }
        preorder(n->left);
        preorder(n->right);
    }
}


Node *minValueNode(Node *root) {
    Node *current = root;

    while (current->left != NULL)
        current = current->left;

    return current;
}

void destroyTree(AVL *t) {
    if (*t == NULL) {
        return;
    }

    destroyTree(&(*t)->left);
    destroyTree(&(*t)->right);

    free((*t)->name);
    free(*t);
    *t = NULL;
}


void deleteNode(AVL *t, char *name) {
    if (*t == NULL) {
        printf("Node with name %s not found\n", name);
        return;
    }

    Node *current = *t;
    Node *parent = NULL;

    // Find the Node to be deleted
    while (current != NULL && strcmp(current->name, name) != 0) {
        parent = current;

        if (strcmp(name, current->name) < 0) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current == NULL) {
        printf("Node with name %s not found\n", name);
        return;
    }

    // Node with only one child or no child
    if (current->left == NULL || current->right == NULL) {
        Node *temp = current->left ? current->left : current->right;

        if (temp == NULL) {
            // No child case
            if (parent) {
                if (parent->left == current) {
                    parent->left = NULL;
                } else {
                    parent->right = NULL;
                }
            } else {
                // Update root if the deleted Node is the root
                *t = NULL;
            }
            free(current);
        } else {
            // One child case
            *current = *temp;
            free(temp);
        }
    } else {
        // Node with two children
        Node *temp = minValueNode(current->right);
        strcpy(current->name, temp->name);

        deleteNode(&current->right, temp->name);
    }

    // Corrected: Update balance factors and check for imbalance after deletion
    adjustbalance_factor(&parent);
    adjustImbalance(t, parent);
}


void removeNode(AVL *t, char *name) {
    deleteNode(t, name);
}

int main() {
    AVL root;
    init(&root);
    char data[1000];
    int n;

    do {
        printf("\n1. Insert\n");
        printf("2. Delete\n");
        printf("3. Destroy Tree\n");
        printf("4. preorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &n);

        switch (n) {
            case 1:
                printf("Enter the data to be inserted (Type 'exit' to stop): ");
                do {
                    scanf("%s", data);
                    if (strcmp(data, "exit") == 0) {
                        break;
                    }
                    insert(&root, data);
                } while (1);
                break;

            case 2:
                printf("Enter the element to be deleted: ");
                scanf("%s", data);
                removeNode(&root, data);
                break;

            case 3:
                printf("Destroying the tree!\n");
                destroyTree(&root);
                printf("Tree destroyed! Run preorder traversal to verify.\n");
                break;

            case 4:
                printf("preorder Traversal: \n");
                preorder(root);
                printf("\n");
                break;

            case 0:
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }

    } while (n != 0);

    return 0;
}
