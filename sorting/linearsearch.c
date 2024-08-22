#include <stdio.h>
#include <stdlib.h>


int main() {
    int a[7] = {8,10,5,4,9,2,3};
    int n = 7;
    int i;
    int flag = 0, temp;
    int searchel;
    printf("Enter the search element:");
    scanf("%d", &searchel);
    for(i = 0; i<n; i++) {
        if(searchel == a[i]) {
            flag = 1;
            temp = i;
            break;

        }
        else {
            flag = 0;
        }
        
    }
    if(flag == 1) {
        printf("The searched element is found in the %dth position of the array.", temp+1);
    }
    else {
        printf("The searched element is not found in the given array.");
    }
}