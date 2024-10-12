#include <stdio.h>
#include <string.h>
int main(){
    int i,n;
    char array[50][50];
    printf("Enter Number for Array: ");
    scanf("%d", &n);
    printf("Enter Array: \n");
    for(i=0; i<n; i++){
        scanf("%s", array[i]);
    }
    for(i=1; i<n; i++){
        char temp[50];
        strcpy(temp, array[i]);
        int j=i-1;
        while(j>=0 && strcmp(array[j], temp) > 0){
            strcpy(array[j+1], array[j]);
            j--;
        }
        strcpy(array[j+1], temp);
    }
    printf("Sorted Array: \n");
    for(i=0; i<n; i++){
        printf("%s\n", array[i]);
    }
    getch();
}
