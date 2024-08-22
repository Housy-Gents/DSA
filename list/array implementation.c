#include <stdio.h>
#include <conio.h>
#include <math.h>
#include <process.h>


void create(int[], int*);
void insert(int[], int*);
void delete(int[], int*);
void update(int[], int*);
void traverse(int[], int*);
void searching(int[], int*);
void merging(int[], int[],int*, int*);
int main() {
    int a[100],b[100],m, n, pos, i;
    int choice;
    printf("Menu for the program:\n");
    printf("1. Create\n2.Insert\n3.Delete\n4.Update\n5.Traverse\n6.Searching\n7.Merging\n8.Exit\n");
    do{
        printf("\nEnter your choice\n");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
            printf("Enter the no. of element of first array:\n");
            scanf("%d", &n);
            create(a,&n);
            break;
            case 2:
            insert(a,&n);
            break;
            case 3:
            delete(a, &n);
            break;
            case 4:
            update(a,&n);
            break;
            case 5:
            traverse(a,&n);
            break;
            case 6:
            searching(a,&n);
            break;
            case 7:
            printf("Enter the size of second array:");
            scanf("%d",&m);
            merging(a,b,&n,&m);
            break;
            case 8:
            exit(0);
            default:
            printf("Invalid Choices!!!");

        } 
    } while(choice<=8);
    return 0;
}
void create(int a[], int *n) {
    int i;
    printf("Enter the element of the array:");
    for(i = 0; i<*n; i++) {
        scanf("%d", &a[i]);
    }
}
void insert(int a[], int *n) {
    int pos, i;
    int el;
    printf("\nEnter the position at which you want to enter the element:");
    scanf("%d", &pos);
    printf("\nEnter the new element:");
    scanf("%d", &el);
    for(i = *n-1;i>=pos;i--) {
        a[i+1] = a[i];
    }
    a[pos] = el;
    *n = *n +1;
}
void delete(int a[], int *n) {
    int pos, i;
    printf("\nEnter the position at which you want to delete the element:");
    scanf("%d", &pos);
    for(i = pos;i<*n;i++) {
        a[i] = a[i+1];
    }
    *n = *n-1;
}

void update(int a[], int *n) {
    int pos, el;
    printf("\nEnter the position at which you want to update the element:");
    scanf("%d", &pos);
    printf("Enter the element:");
    scanf("%d", &el);
    a[pos] = el;
}
void traverse(int a[], int *n) {
    int i;
    printf("The elements of the array are:\n");
    for(i = 0; i<*n; i++) {
        printf("%d\t", a[i]);
    }
}
void searching(int a[], int *n) {
    int num, i;
    printf("\nEnter the number to be searched:");
    scanf("%d", &num);
    for(i = 0; i<*n;i++) {
        if(num == a[i]) {
            printf("Search successful!!");
            break;
        }
    }
    if(i == *n) {
        printf("Element is not found in the array!!");
    }
}
void merging(int a[],int b[], int *n, int *m) {
    int i, j = *n;
    printf("\nEnter the element of second array:");
    for(i = 0; i<*m; i++) {
        scanf("%d", &b[i]);
        a[j] = b[i];
        j++;
        *n = *n+1;
    }
}

