#include <stdio.h>
#include <conio.h>

int main(){
    int i;
    int arr[5];
    int find;
    int flag=0;
    printf("Enter the array Elements: \n");
    for(i=0; i<5; i++){
            scanf("%d", &arr[i]);
    }
    printf("Enter Element to Search: ");
    scanf("%d", &find);
    for(i=0; i<5; i++){
            if(find==arr[i]){
                             flag++;
            }
    }
    printf("\nElement has Occured only %d time", flag);
    getch();
}
                             
    
            
