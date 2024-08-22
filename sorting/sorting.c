#include <stdio.h>
#include <stdlib.h>

void bubblesort(int [], int );
void selectionsort(int [], int);
void insertionsort(int [], int);
void shellsort(int[], int);
void quicksort(int[], int, int);
int partition(int [], int, int);
void mergesort(int[], int, int);
void merge(int [], int, int, int);

int main() {
    int a[7] = {8,10,5,4,9,2,3};
    int n = 7;
    int i;
    int l = 0, r = n-1;
    printf("\nBefore Sorting:\n");
    for(i = 0; i<n; i++) {
        printf("%d\t", a[i]);
    }
    bubblesort(a,n);
    printf("\nBubble sort:\n");
    for (i = 0; i<n; i++) {
        printf("%d\t", a[i]);
    }
    selectionsort(a,n);
    printf("\nSelection sort:\n");
    for (i = 0; i<n; i++) {
    printf("%d\t", a[i]);
    }
    insertionsort(a,n);
    printf("\nInsertion sort:\n");
    for (i = 0; i<n; i++) {
    printf("%d\t", a[i]);
    }
    shellsort(a,n);
    printf("\nShell sort:\n");
    for (i = 0; i<n; i++) {
    printf("%d\t", a[i]);
    }
    quicksort(a,l,r);
    printf("\nQuick sort:\n");
    for (i = 0; i<n; i++) {
    printf("%d\t", a[i]);
    }
    mergesort(a,l,r);
    printf("\nMerge sort:\n");
    for (i = 0; i<n; i++) {
    printf("%d\t", a[i]);
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
void selectionsort(int a[], int n) {
    int i, j, least, p, temp;
    for (i = 0; i<n; i++) {
        least = a[i];
        p = i;
        for(j = i+1; j<n; j++) {
            if (a[j]<least) {
                least = a[j];
                p = j;
            }
        }
        if(i!=p) {
        temp = a[i];
        a[i] = a[p];
        a[p] = temp;
        }
    }
}
void insertionsort(int a[], int n) {
    int i, j, temp;
    for (i = 0; i<n; i++) {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp){
            a[j+1] = a[j];
            j--;
        }
    }
    a[j+1] = temp;
}
void shellsort(int a[], int n) {
    int incre,i,j, temp;
    for(incre = n/2; incre > 0; incre /=2) {
        for (i = incre;i<n;i++) {
            temp = a[i];
            for (j = i; j>=incre;j-=incre) {
                if (temp<a[j-incre]) {
                    a[j] = a[j - incre];
                }
                else {
                    break;
                }
            }
            a[j] = temp;
        }
    }
}
//Quick Sort
void quicksort(int a[], int l, int r) {
    int p;
    if(l<r) {
        p = partition(a,l,r);
        quicksort(a,l,p-1);
        quicksort(a,p+1,r);
    }
    
}
int partition(int a[], int l, int r) {
    int x = l, y = r, p = a[l];
    int temp;
    while(l<r) {
        while(a[x] <= p) {
            x++;
        }
        while(a[y] >= p) {
            y--;
        }
        if(x<y) {
            temp = a[x];
            a[x] = a[y];
            a[y] = temp;
        }
    }
    a[l] = a[y];
    a[y] = p;
    return y;
}
//Merge sort
void mergesort(int a[], int l, int r) {
    int mid;
    if (l<r) {
        mid = (l+r)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,r);
        merge(a,l,mid+1,r);
    }
}
void merge(int a[], int l, int m, int r) {
    int x=l, k = l, i, y = m;
    int b[7];
    while(x<m && y<=r) {
        if (a[x]<a[y]) {
            b[k] = a[x];
            k++;
            x++;
        }
        else{
            b[k] = a[y];
            k++;
            y++;
        }
    }
    while(x<m) {
        b[k] = a[x];
        k++;
        x++;
    }
    while(y<=r) {
        b[k] = a[y];
        y++;
        k++;
    }
    for (i = l; i<= r; i++) {
        a[i] = b[i];
    }
}