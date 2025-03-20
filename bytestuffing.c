#include<stdio.h>
#include<conio.h>

void main(){
    int count=0,s,i,consecutiveCount=0;
    int a[16];

    printf("\n Enter the size of the bit array (between 1 and 16): ");
    scanf("%d",&s);

    if (s < 1 || s > 16) {
        printf("Invalid size. Please enter a value between 1 and 16.\n");
        return;
    }

    printf("\n Enter the bits (1 or 0) in the array of size %d: ",s);
    for (int i = 0; i < s; i++)
    {
        scanf("%d",&a[i]);
        if (a[i] != 0 && a[i] != 1) {
            printf("Invalid input. Please enter 0 or 1.\n");
            return;
        }
        if (a[i] == 1) {
            consecutiveCount++;
        } else {
            consecutiveCount = 0;
        }
        if (consecutiveCount >= 5) {
            count = 5;
        }
    }
    
    printf("\nYour entered bit in array is : ");
    for (int i = 0; i < s; i++){
        printf("%d",a[i]);
    }

    if (count == 5) {
        printf("\nBits are buffered.\n");
        for (i = 0; i < count; i++) {
            printf("%d", a[i]);
        }
        printf("0");
    } else {
        printf("\nBits are not buffered.\n");
        for (i = 0; i < s; i++) {
            printf("%d", a[i]);
        }
    }
}