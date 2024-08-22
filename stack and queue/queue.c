#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct queue {
    int item[MAX];
    int front;
    int rear;
};
typedef struct queue q;
void IsEmpty(q *);
void IsFull(q *);
void Enqueue(q *, int);
void Dequeue(q *);
void Traverse(q *);

int main() {
    q * q1;
    q1 = (q*) malloc(sizeof(q));
    q1->rear = -1;
    q1->front = 0;
    int choice, item;
    do {
        printf("Enter the choice:");
        scanf("%d", &choice);
        switch(choice) {
              case 1:
            printf("Enter the item to push to queue:");
            scanf("%d", &item);
            Enqueue(q1, item);
            break;
            case 2:
            Dequeue(q1);
            break;
            case 3:
            IsEmpty(q1);
            break;
            case 4:
            IsFull(q1);
            break;
            case 5:
            Traverse(q1);
            break;
            default:
            printf("Invalid Input");
        }
    }while (choice < 6);
}
void Enqueue(q * q1, int item) {
    if (q1->rear == MAX-1) {
        printf("Queue Overflow");
    }
    else {
        q1->rear += 1;
        q1->item[q1->rear] = item;
    }
}
void Dequeue(q * q1) {
    if (q1->rear < q1->front) {
        printf("Queue is Empty");
    }
    else {
        printf("%d is dequeued.", q1->item[q1->front]);
        q1->front += 1;
    }
}
void IsEmpty(q * q1) {
    if(q1->rear<q1->front) {
        printf("Queue is Empty");
    }
    else {
        printf("Queue is not Empty");
    }
}
void IsFull(q * q1) {
    if(q1->rear == MAX -1) {
        printf("Queue is FUll");
    }
    else {
        printf("Queue is not FULL");
    }
}
void Traverse(q * q1) {
    int i;
    if (q1->rear < q1->front) {
        printf("Queue is Empty");
    }
    else {
        for (i = q1->front; i<=q1->rear;i++) {
            printf("%d\t", q1->item[i]);
        } 
    }
}

