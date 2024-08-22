#include <stdio.h>
#include <stdlib.h>

struct Node{
    int item;
    struct Node *next;
    struct Node *prev;
};
typedef struct Node Node;
Node *first = NULL;
Node *last = NULL;
void insertb(int );
void inserte(int);
void deleteb();
void deletee();
void display();

int main() {
    int choice;
    int item;
    do{
        printf("enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("Enter the item to insert:");
            scanf("%d", &item);
            insertb(item);
            break;
            case 2:
            printf("Enter the item to insert:");
            scanf("%d", &item);
            inserte(item);
            break;
            case 3:
            deleteb();
            break;
            case 4:
            deletee();
            break;
            case 5:
            display();
            break;
            default:
            printf("Invalid Input!");
        } 
    }while(choice < 6);
}
void insertb(int item) {
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->item = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(first == NULL) {
        first = newnode;
        last = newnode;
    }
    else {
        newnode->next = first;
        first->prev = newnode;
        first = newnode;
    }
}

void inserte(int item) {
    Node *newnode;
    newnode = (Node*) malloc(sizeof(Node));
    newnode->item = item;
    newnode->next = NULL;
    newnode->prev = NULL;
    if(first == NULL) {
        first = newnode;
        last = newnode;
    }
    else {
        last->next = newnode;
        newnode->prev = last;
        last = newnode;
    }
}

void deleteb() {
    Node *temp;
    temp = first;
    if (first == NULL) {
        printf("Void Deletelion");
        exit(1);
    }
    else{
        first = first->next;
    }
    free(temp);
}

void deletee() {
    Node *temp, *hold;
    temp = first;
    if(first == NULL) {
        printf("Void Deletion");
        exit(1);
    }
    else {
        while(temp->next != last) {
            temp = temp->next;
        }
        hold = temp->next;
        last = hold->prev;
        last->next = NULL;
    }
    free(hold);
}

void display() {
    Node *temp;
    temp = first;
    if(first == NULL) {
        printf("The linked list is empty.");
        exit(1);
    }
    else{
        while(temp != NULL) {
            printf("%d\t", temp->item);
            temp = temp->next;
        }
    }
}