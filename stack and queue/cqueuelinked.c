#include <Stdio.h>
#include <stdlib.h>

struct Linkedcqueue {
    int item;
    struct Linkedcqueue *next;
};
typedef struct Linkedcqueue lcq;
lcq *q = NULL;
void insert(item);
void delete();
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
            default:
            printf("Invalid Input");
        }
    }while (choice < 3);
}
void insert(int item) {
    lcq *cq;
    cq = (lcq *)malloc(sizeof(lcq));
    cq->item = item;
    if(q == NULL) {
        q = cq;
    }
    else {
        cq->next = q->next;
        q->next = cq;
        q = cq;
    }
}
void delete() {
    lcq *temp;
    if(q == NULL) {
        printf("QUEUE IS EMPTY");
        exit(1);
    }
    else if(q->next == q) {
        printf("POPPED ITEM %d", q->item);
        q = NULL;
    }
    else {
        temp = q->next;
        q->next = temp->next;
        printf("POPPED ITEM %d", temp->item);
        free(temp);
    }
}
