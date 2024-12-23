#include <stdio.h>
#include <conio.h>
int main(){
    int i,n, array[50];
    printf("Enter Number for Array: ");
    scanf("%d", &n);
    printf("Enter Array: \n");
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    for(i=1; i<n; i++){
        int temp=array[i];
        int j=i-1;
        while(j>=0 && array[j]>temp){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=temp;
    }
    printf("Sorted Array: \n");
    for(i=0; i<n; i++){
        printf("%d\n", array[i]);
    }
    getch();
}

/*[?2004l
Enter Number for Array: 3
Enter Array: 
6
35
25
Sorted Array: 
6
25
35
[?2004h*/