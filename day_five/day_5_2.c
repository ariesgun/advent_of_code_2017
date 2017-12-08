#include <stdio.h>

int main() {

	int arr[1256] = {0};
	int size = 0;
	int end = 0, val = 0;

	do {
		end = scanf("%d", &val);
		arr[size] = val;
		size++;
	} while (end != EOF);

	// Calculate the number of steps.
	int steps = 0;
	int pos = 0;

	while ((pos < size - 1) && pos >= 0) {
		int temp = arr[pos];
		if (arr[pos] >= 3) {
			arr[pos] = arr[pos] - 1;
		} else {
			arr[pos] = arr[pos] + 1;
		}
		pos += temp;
		steps++;
	}

	printf("Result %d steps\n", steps);

	return 0;

}