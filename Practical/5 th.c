#include<stdio.h>
#include<string.h>
#include<conio.h>

int main() {
	int flag=0;
	int i,n,last,mid,res;
	char array[50][50];
	char find[50];
	int first=0;
	printf("Enter the Number for Array: ");
	scanf("%d", &n);
	last=n-1;
	printf("Enter Array: \n");
	for(i=0; i<n; i++) {
		scanf("%s", array[i]);
	}
	printf("Find String is: ");
	scanf("%s", find);
	while(first<=last) {
		mid=(first+last)/2;
		res=strcmp(array[mid], find);
		if(res<0) {
			first=mid+1;
		} else if(res==0) {
			printf("Elements Found at Index %d", mid);
			break;
		} else {
			last=mid-1;
		}
	}
	if(first>last) {
		printf("Elements Not Found");
	}
	getch();
}

/*[?2004l
Enter the Number for Array: 3
Enter Array:
Aarya
Abhishek
Vivek
Find String is: Vivek
Elements Found at Index 2
[?2004h*/