#include <stdio.h>
#include <stdlib.h>

struct Node {
    int item;
    struct Node *next;
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
    do {
        printf("\nEnter your choice:");
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
    }while (choice < 6);
}

void insertb(int item) {
    Node *newnode;
    newnode = (Node*) malloc(sizeof(Node));
    newnode->item = item;
    newnode->next = NULL;
    if(first == NULL) {
        first = newnode;
        last = first;
    }
    else {
        newnode->next = first;
        first = newnode;
        last->next = first;
    }
}

void inserte(int item) {
    Node *newnode;
    newnode = (Node*)malloc(sizeof(Node));
    newnode->item = item;
    newnode->next = NULL;
    if(first == NULL) {
        first = newnode;
        last = newnode;
    }
    else {
        newnode->next = first;
        last->next = newnode;
        last = newnode;
    }
}

void deleteb() {
    Node *temp;
    temp = first;
    if(first == NULL) {
        printf("The linked list is empty");
        exit(1);
    }
    else{
        first = first->next;
        last->next = first;
    }
    free (temp);
}

void deletee() {
    Node *temp, *hold;
    temp = first;
    if(first == NULL) {
        printf("The linked list is empty:");
        exit(1);
    }
    else {
        while (temp->next != last) {
            temp = temp->next;
        }
        hold = temp->next;
        last = temp;
        last->next = first;
    }
    free(hold);
}

void display() {
    Node *temp;
    temp = first;
    if(first  == NULL) {
        printf("The linked list is empty:");
        exit(1);
    }
    else {
        while(temp != last) {
            printf("%d\t", temp->item);
            temp = temp->next;
        }
        printf("%d", last->item);
    }
}