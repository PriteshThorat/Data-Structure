#include <stdio.h>
#include <conio.h>

int main()
{
    int array[50];
    int n,i,j,min;
    printf("Enter Number for Array: ");
    scanf("%d",&n);
    printf("Enter Array: \n");
    for(i=0; i<n;i++){
        scanf("%d", &array[i]);
    }
    for(i=0; i<n-1; i++){
        min = array[i];
        int loc=i;
        for(j=i+1; j<n; j++){
            if(min > array[j]){
                   min = array[j];
                   loc=j;
            }
        }
        int temp = array[i];
        array[i] = array[loc];
        array[loc] = temp;
    }
    printf("Sorted Array: \n");
    for(i=0; i<n; i++){
        printf("%d\n", array[i]);
    }
    getch();
}
