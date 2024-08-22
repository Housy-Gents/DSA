#include <stdio.h>
#include <stdlib.h>
#define MAX 20
struct Stack {
    int item[MAX];
    int top;
};
typedef struct Stack st;
void IsEmpty(st *);
void Push(st *, int );
void Pop(st *);
void display(st *);
void IsFull(st *);

int main() {
    st *s;
    s = (st*)malloc(sizeof(st));
    s->top = -1;
    int choice;
    int item;
    do {
        printf("Enter your choice:");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("Enter the item to push to stack:");
            scanf("%d", &item);
            Push(s, item);
            break;
            case 2:
            Pop(s);
            break;
            case 3:
            IsEmpty(s);
            break;
            case 4:
            IsFull(s);
            break;
            case 5:
            display(s);
            break;
            default:
            printf("Invalid Input");
        }
    }while (choice < 6);
}
void Push(st *s, int item) {
    if(s->top == MAX-1) {
        printf("The stack is Full");
        
    }
    else {
        s->top = s->top + 1;
        s->item[s->top] = item;
    }
}
void Pop(st *s) {
    if(s->top == -1) {
        printf("The stack is Empty");
        exit(1);
        
    }
    else {
        printf("%d is the popped item.", s->item[s->top]);
        --s->top;
    }
}
void IsEmpty(st *s) {
    if(s->top == -1) {
        printf("The stack is empty");
    }
    else {
        printf("There are item in stack.");
    }
}
void IsFull(st *s) {
    if(s->top == MAX-1) {
        printf("The stack is Full");
    }
    else {
        printf("The stack is not full.");
    }
}
void display(st *s) {
    int i;
    if (s->top == -1) {
        printf("The stack is Empty.");
        
    }
    else {
        for(i = 0; i<=s->top;i++) {
            printf("%d\t", s->item[i]);
        }
    }
}
