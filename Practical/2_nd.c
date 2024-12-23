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
                             flag=1;
                             printf("The Element is at %d Position", i);
            }
    }
    if(flag==0){
                printf("\nElement not Found");
    }
    getch();
}

/*[?2004l
Enter the array Elements: 
3
5
2
6
3
Enter Element to Search: 6
The Element is at 3 Position[?2004h*/