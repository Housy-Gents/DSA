#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Node {
    int info;
    struct Node *next;
};
typedef struct Node Nodetype;
Nodetype *first= NULL;
Nodetype *last = NULL;
void insert(int);
void display();
void delete();
void insertlast(int);
void insertp(int);
void deletelast();
void deletep();
int main() {
    int item;
    int choice;
    do{
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1: 
            printf("Enter the item you want to insert:");
            scanf("%d", &item);
            insert(item);
            break;
            case 2:
            printf("Enter the item:");
            scanf("%d", &item);
            insertlast(item);
            break;
            case 3:
            printf("Enter the item:");
            scanf("%d",&item);
            insertp(item);
            break;
            case 4:
            display();
            break;
            case 5:
            delete();
            break;
            case 6:
            deletelast();
            break;
            case 7:
            deletep();
            break;
            default:
            printf("Invalid Input!!!");
        }
    }while(choice<=7);

}

void insert(int item) {
    Nodetype *newnode;
    newnode = (Nodetype*)malloc(sizeof(Nodetype));
    newnode->info = item;
    if(first == NULL){
        newnode->next = NULL;
        first = newnode;
        last = newnode;
    }
    else {
        newnode->next = first;
        first = newnode;
    }
}
void insertlast(int item) {
    Nodetype *newnode;
    newnode = (Nodetype*)malloc(sizeof(Nodetype));
    newnode->info=item;
    if(first == NULL) {
        newnode->next = NULL;
        first = newnode;
        last = newnode;
    }
    else{
        last->next = newnode;
        newnode->next = NULL;
        last = newnode;
    }
}
void insertp(int item) {
    Nodetype *newnode;
    Nodetype *temp;
    newnode = (Nodetype*) malloc(sizeof(Nodetype));
    int pos,i;
    printf("Enter the position of the newnode:");
    scanf("%d", &pos);
    newnode->info = item;
    temp = first;
    if(first == NULL) {
        printf("Invalid insertion!!");
        exit(0);
    }
    else{
        for(i = 0; i<pos-1; i++) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        temp->next = newnode;
    }
}
void display() {
    Nodetype *temp;
    temp = first;
    if (first == NULL) {
        printf("Empty linked list!!!");
        exit(1);
    }
    else {
        while(temp != NULL) {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
    }
}
void delete() {
    Nodetype *temp;
    temp = first;
    if(first == NULL) {
        printf("Empty linked list!!");
        exit(1);
    }
    else{
        first = first->next;
        printf("%d is the first element.", temp->info);
    }
    free(temp);
}
void deletelast() {
    Nodetype *temp;
    temp = first;
    if(first == NULL) {
        printf("Empty linked list!!");
        exit(1);
    }
    else {
        while(temp->next != last) {
            temp = temp->next;
        }
        free(last);
        last = temp;
        last->next = NULL;
     }
}
void deletep() {
    Nodetype *temp, *hold;
    int p, i;
    temp = first;
    
    if(first == NULL) {
        printf("Void Deletion!!");
        exit(1);
    }
    else {
    printf("Enter the position of the element:");
    scanf("%d", &p);
    for(i = 0; i<p-1; i++) {
        temp = temp->next;
    }
    hold = temp->next;
    temp->next = hold->next;
    printf("The deleted element is:%d", hold->info);
    }
    free(hold);

}