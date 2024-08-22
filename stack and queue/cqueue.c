#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct cqueue{
    int item[MAX];
    int rear;
    int front;
};
typedef struct cqueue cq;
void insert(cq *, int);
void delete(cq *);
void display(cq *);
int main() {
     int choice;
    int item;
    cq *c;
    c = (cq *)malloc(sizeof(cq));
    c->rear = MAX-1;
    c->front = MAX -1;
    do{
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("Enter the item to push:");
            scanf("%d", &item);
            insert(c,item);
            break;
            case 2:
            delete(c);
            break;
            case 3:
            display(c);
            break;
            default:
            printf("Invalid Input");
        }
    }while (choice < 4);
}
void insert(cq *c, int item) {
    if(c->front == (c->rear+1)%MAX) {
        printf("QUEUE IS FULL");
        exit(1);
    }
    else {
        c->rear = (c->rear+1)%MAX;
        c->item[c->rear]  = item;
    }
}
void delete(cq *c) {
    if(c->rear == c->front) {
        printf("QUEUE is EMPTY");
        exit(1);
    }
    else {
        c->front = (c->front+1)%MAX;
        printf("THE ITEM DELETED IS %d", c->item[c->front]);

    }
}
void display(cq *c) {
    int i;
    if (c->rear == c->front) {
        printf("QUEUE IS EMPTY");
        exit(1);
    }
    else {
        for(i= (c->front+1)%MAX;i!=c->rear;i = (i+1)%MAX){
            printf("%d\t", c->item[i]);

        }
        printf("%d", c->item[c->rear]);
    }
}