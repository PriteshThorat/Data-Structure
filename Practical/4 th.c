#include<stdio.h>
#include<conio.h>
int main() {
	int flag=0;
	int i,n,array[50],find,last,mid;
	int first=0;
	printf("Enter the Number for Array: ");
	scanf("%d", &n);
	last=n-1;
	printf("Enter Array: \n");
	for(i=0; i<n; i++) {
		scanf("%d", &array[i]);
	}
	printf("Find Number is: ");
	scanf("%d", &find);
	while(first<=last) {
		mid=(first+last)/2;
		if(array[mid]<find) {
			first=mid+1;
		} else if(array[mid]==find) {
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
Enter the Number for Array: 5
Enter Array:
2
5
8
10
15
Find Number is: 10
Elements Found at Index 3[?2004h*/