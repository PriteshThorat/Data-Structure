#include <stdio.h>
#include <string.h>

int main()
{
    int i,j;
    char array[50][50];
    int n;
    printf("Enter Number for Array: ");
    scanf("%d",&n);
    printf("Enter Array of String: \n");
    for(i=0; i<n;i++){
        scanf("%s",array[i]);
    }
    for(i=0; i<n-1; i++){
        char min[50];
        strcpy(min, array[i]);
        int loc=i;
        for(j=i+1; j<n; j++){
            if(strcmp(min, array[j])>0){
                strcpy(min, array[j]);
                loc=j;
            }
        }
        char temp[50];
        strcpy(temp, array[i]);
        strcpy(array[i], array[loc]);
        strcpy(array[loc], temp);
    }
    printf("Sorted Array: \n");
    for(i=0; i<n; i++){
        printf("%s\n",array[i]);
    }

    getch();
}
