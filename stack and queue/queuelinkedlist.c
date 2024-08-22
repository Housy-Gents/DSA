#include <stdio.h>
#include <stdlib.h>

struct Linkedqueue{
    int item;
    struct Linkedqueue *next;
};
typedef struct Linkedqueue lq;
lq *rear = 0;
lq *front = 0;
void insert(int);
void delete();
void display();

int main() {
     int choice;
    int item;
    do{
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("Enter the item to push:");
            scanf("%d", &item);
            insert(item);
            break;
            case 2:
            delete();
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid Input");
        }
    }while (choice < 4);
}
void insert(int item) {
    lq *q;
    q = (lq *) malloc(sizeof(lq));
    if(rear == 0) {
        q->item = item;
        q->next = NULL;
        rear = q;
        front = q;
    }
    else {
        q->item = item;
        q->next = NULL;
        rear->next = q;
        rear = q;
    }
}
void delete() {
    lq *temp;
    if(front == 0) {
        printf("Queue is Empty");
        exit(1);
    }
    else if(front->next == NULL) {
        temp = front;
        rear = NULL;
        front = NULL;
        free(temp);
    }
    else {
        temp = front;
        front = front->next;
        printf("The deleted item is %d.", temp->item);
        free(temp);    
    }
}
void display() {
    lq *temp;
    temp = front;
    while (temp != NULL) {
        printf("%d\t", temp->item);
        temp = temp->next;
    }
}
