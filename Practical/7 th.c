#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    int i,n,pass,j;
    char array[50][50];
    printf("Enter Number for Array: ");
    scanf("%d", &n);
    printf("Enter Array:\n");
    for(i=0; i<n; i++){
        scanf("%s", array[i]);
    }
    for(pass=1; pass<n; pass++){
        for(j=0; j<n-pass; j++){
            if(strcmp(array[j], array[j+1]) > 0){
                char temp[50];
                strcpy(temp, array[j]);
                strcpy(array[j], array[j+1]);
                strcpy(array[j+1], temp);
            }
        }
    }
    printf("Sorted Array: \n");
    for(i=0; i<n; i++){
        printf("%s\n", array[i]);
    }
    getch();
}
