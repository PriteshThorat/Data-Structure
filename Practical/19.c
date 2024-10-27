#include <stdio.h>
void printReverse(char *str) {
	if (*str == '\0') {
		return;
	}

	printReverse(str + 1);
	printf("%c", *str);
}
int main() {
	char str[100];

	printf("Enter a string: ");
	scanf("%s", str);
	printf("The string in reverse is: ");
	printReverse(str);
	printf("\n");
	return 0;
}

/*[?2004l
Enter a string: Vivek
The string in reverse is: keviV
[?2004h*/