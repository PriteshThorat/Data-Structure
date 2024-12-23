#include<stdio.h>
#include<conio.h>
#include<string.h>

int main() {
	int i;
	int isFound=0;
	char name[15][15];
	char find[15];
	printf("Enter Five Elements: \n");
	for(i=0; i<5; i++) {
		scanf("%s", name[i]);
	}
	printf("Enter Name To Find: ");
	scanf("%s", find);
	for(i=0; i<5; i++) {
		if(strcasecmp(name[i], find) == 0) {
			printf("Name has been found");
			isFound=1;
		}
	}
	if(isFound == 0) {
		printf("Name hasn't Found");
	}
	getch();
}

