#include <stdio.h>
#include <stdlib.h>

struct BST {
    int item;
    struct BST *left;
    struct BST *right;
};
typedef struct BST BS;
BS *root = NULL;

void insertion(BS **, int);
void delete(BS **, int );
void inorder(BS *);
void preorder(BS *);
void postorder(BS *);
void search(BS **, int);

int main() {
    int item;
    int choice;
    do {
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        printf("Enter the item");
        scanf("%d", &item);
        insertion(&root, item);
        break;
        case 2:
        inorder(root);
        break;
        case 3:
        preorder(root);
        break;
        case 4:
        postorder(root);
        break;
        case 5:
        printf("Enter the item to delete:");
        scanf("%d", &item);
        delete(&root,item);
        break;
        
        default:
            break;
        }
    }while(choice < 6);
    
}
void insertion(BS **root, int item) {
    if(*root == NULL) {
        BS *newnode = (BS *)malloc(sizeof(BS));
        newnode->item = item;
        newnode->left = NULL;
        newnode->right = NULL;
        *root = newnode;
    }
    else 
    {
        if (item <(*root)->item) {
            insertion(&((*root)->left),item);
        }
        else {
            insertion(&((*root)->right),item);
        }
    }
}
void inorder(BS *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d\t", root->item);
        inorder(root->right);
    }
}
void preorder(BS *root) {
    if(root != NULL) {
        printf("%d\t", root->item);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(BS*root) {
    if(root != NULL) {
        preorder(root->left);
        preorder(root->right);
        printf("%d\t", root->item);

    }
}
void delete(BS **root, int item) {
    int found;
    BS *parent, *x, *xsucc;
    if(*root == NULL) {
        printf("Tree is empty:");
        exit(1);
    }
    parent = NULL;
    x = NULL;
    search(&root, item);
    if(found == 0) {
        printf("Data to be deleted not found");
        return;
    }
    //if the node to be deleted has two children
    if(x->left != NULL && x->right != NULL) {
        parent = x;
        xsucc= x->right;
        while(xsucc->left != NULL) {
            parent = xsucc;
            xsucc = xsucc->left;
        }
        x->item = xsucc->item;
        x = xsucc;
    }
    //if the node to be deleted has no children
    if(x->left == NULL && x->right == NULL) {
        if(parent->right == x) {
            parent->right = NULL;
        }
        else {
            parent->left = NULL;        
        }
        free(x);
        return;
    }
    //if the node to be deleted has only right child
    if(x->left == NULL && x->right != NULL) {
        if(parent->left == x) {
            parent->left = x->right;
        }
        else {
            parent->right = x->right;
        }
        free(x);
        return;
    }
    //if the node to be deleted has only left child
    if(x->left != NULL && x->right == NULL) {
        if(parent->left == x) {
            parent->left = x->left;
        }
        else {
            parent->right = x->left;
        }
        free(x);
        return;
    }
}
void search(BS **root, int item) {
    BS *parent, **x, **par, *q;
    q = *root;
    int found = 0;
    *par = NULL;
    while(q != NULL) {
        if(q->item == item) {
            found = 1;
            *x = q;
            return;
        }
        if(q->item > item) {
            q = q->left;
        }
        else {
            q = q->right;
        }
    }

    

}