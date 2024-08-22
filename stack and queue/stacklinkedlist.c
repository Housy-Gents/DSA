#include <stdio.h>
#include <stdlib.h>

struct LinkedStack{
    int item;
    struct LinkedStack *next;
};
typedef struct LinkedStack ls;
ls *top = NULL;
void Push(int);
void Pop();
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
            Push(item);
            break;
            case 2:
            Pop();
            break;
            case 3:
            display();
            break;
            default:
            printf("Invalid Input");
        }
    }while (choice < 4);
}
void Push(int item) {
    ls *s;
    s = (ls *)malloc(sizeof(ls));
    if(top == NULL) {
        s->item = item;
        s->next = NULL;
        top = s;
    }
    else {
        s->item = item;
        s->next = top;
        top = s;
    }
}
void Pop() {
    ls *temp;
    if(top == NULL) {
        printf("The stack is empty:");
        exit(1);
    }
    else {
        temp = top;
        printf("%d is popped", temp->item);
        top = top->next;
        free(temp);
    }
}
void display() {
    ls *temp;
    if(top == NULL) {
        printf("The stack is empty");
        exit(1);
    }
    else {
        temp = top;
        while(temp != NULL) {
            printf("%d\t", temp->item);
            temp = temp->next;

        }
    }
}