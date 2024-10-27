#include <stdio.h>
int multiply(int a, int b) {
	if (b == 0) {
		return 0;
	}

	if (b < 0) {
		return -multiply(a, -b);
	}
	return a + multiply(a, b - 1);
}
int main() {
	int num1, num2;
	printf("Enter two numbers to multiply: ");
	scanf("%d %d", &num1, &num2);
	int result = multiply(num1, num2);
	printf("The multiplication of %d and %d is: %d\n", num1, num2, result);
	return 0;
}

/*[?2004l
Enter two numbers to multiply: 5
3
The multiplication of 5 and 3 is: 15
[?2004h*/