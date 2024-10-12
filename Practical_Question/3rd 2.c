#include<stdio.h>
#include<conio.h>
#include<string.h>

int main(){
    int i;
    int isFound=0;
    char name[15][15];
    char subString[15];
    printf("Enter Five Strings: \n");
    for(i=0; i<5; i++){
             gets(name[i]);
    }
    printf("Enter Substring To Find: ");
    scanf("%s", subString);
    for(i=0; i<5; i++){
             //printf("%s\n", strstr(name[i], subString));
             if(strstr(name[i], subString) != NULL){
                                printf("Substring has been found in ");
                                puts(name[i]);
                                isFound=1;
             }
    }
    if(isFound == 0){
               printf("Substring hasn't Found!");
    }
    getch();
}
    
