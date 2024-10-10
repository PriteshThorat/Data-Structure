#include <stdio.h>
#include <conio.h>

int main(){
    int i;
    int rollNo[50];
    char name[50][50];
    int find,n;
    int flag=0;
    printf("Enter the Student Entries: ");
    scanf("%d", &n);
    for(i=0; i<n; i++){
             printf("\nEnter Roll No: ");
             scanf("%d", &rollNo[i]);
             printf("Enter Student Name: ");
             scanf("%s", name[i]);
    }
    printf("\nEnter Roll No to Search: ");
    scanf("%d", &find);
    for(i=0; i<n; i++){
            if(find==rollNo[i]){
                             flag=1;
                             printf("\nThe Roll No: %d\nStudent Name: %s", rollNo[i], name[i]);
            }
    }
    if(flag==0){
                printf("\nRoll Number Not Found");
    }
    getch();
}
                             
    
            
