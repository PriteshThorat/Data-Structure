#include<stdio.h>
#include<conio.h>
int main(){
    int flag=0;
    int i,n,array[20],arrI[20],last,mid;
    int first=0;
    int find=3;
    printf("Enter Size of  Array: ");
    scanf("%d", &n);
    last=n-1;
    printf("Enter Array: \n");
    for(i=0; i<n; i++){
             scanf("%d", &array[i]);
    }
    i=0;
    while(first<=last){
                       mid=(first+last)/2;
                       if(array[mid]<find){
                                         first=mid+1;
                                         i++;
                                         if(i-1==20){
                                                     break;
                                         }
                       } else if(array[mid]==find){
                                          arrI[20]=mid;
                       } else {
                                          last=mid-1;
                       }
    }
    if(first>last){
                   printf("Elements Not Found");
    }else {
          printf("First Occurance: %d", arrI[0]);  
          printf("Last Occurance: %d", arrI[i-1]);
    }     
    getch();
}               
                              
    
