#include<stdio.h>
#include<conio.h>

int main(){
    int pass, j, i, n, array[50];
    printf("Enter Number for Array: ");
    scanf("%d", &n);
    printf("Enter Array:\n");
    for(i=0; i<n; i++){
        scanf("%d", &array[i]);
    }
    for(pass=1; pass<n; pass++){
        for(j=0; j<n-pass; j++){
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }
        }
    }
    printf("Sorted Array: \n");
    for(i=0; i<n; i++){
        printf("%d\n", array[i]);
    }
    getch();
}

/*[?2004l
Enter Number for Array: 6
Enter Array:
2
8
46
53
265
74
Sorted Array: 
2
8
46
53
74
265
[?2004h*/