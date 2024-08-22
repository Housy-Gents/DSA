#include <stdio.h>
#include <stdlib.h>

int binarysearch(int [], int, int, int ) ;
void bubblesort(int[], int);

int main() {
    int a[7] = {8,10,5,4,9,2,3};
    int n = 7;
    int l = 0;
    int r = n-1;
    int key;
    int flag;
     bubblesort(a,n);
    printf("Enter the search element:");
    scanf("%d", &key);
    flag = binarysearch(a,l,r,key);
    if(flag == 0) {
        printf("Element is not found!");
    }
    else {
        printf("Element is  found!");
    }
}    
int binarysearch(int a[], int l, int r, int key) {
    int m;
    int flag = 0;

    if(l<=r) {
        m = (l+r)/2;
        if (a[m] == key) {
            flag = m;
        } 
        else if(key < a[m]) {
             return binarysearch(a,l,m-1, key);
        }
        else {  
            return binarysearch(a,m+1,r, key);
        }
    }
    else{
    return flag;
    }
}
void bubblesort(int a[], int n) {
    int i, j, temp;
    for(i = 0; i<n-1;i++) {
        for(j = 0; j<n-i-1; j++) {
            if (a[j]>a[j+1]) {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }

}