#include<stdio.h>

int main() {
	
	int len = 0;
	short first = 0, prev = 0, next = 0;
	int result = 0;
	char ch;
	short end;

	short arr[2056];

	// Scan the input
	do {
		end = scanf(" %d", &arr[len]);
		len++;
	} while (end != EOF);

	short half = len/2;

	// Process it
	for (int i = 0; i < len; i++) {
		if (i < half) {
			result += (arr[i] == arr[i+half]) ? arr[i] : 0;
		} else if (i >= half) {
			result += (arr[i] == arr[i-half]) ? arr[i] : 0;
		}
	}

	printf("Result is %d\n", result);

	return 0;

}