#include<stdio.h>

int main() {
	
	int len = 0;
	short first = 0, prev = 0, next = 0;
	int result = 0;
	char ch;
	short end;

	do {
		// Scan the input file.
		end = scanf(" %c", &ch);
		// Process it
		if (end != EOF) {
			next = ch - '0';
			//printf("%d\n", next);
			if (len == 0) {
				first = next;
			} else {
    			if (prev == next) {
	    			result += prev;
		    	}
			}
			len++;
			prev = next;
		} else {
			// End of string
			if (prev == first) {
				result += prev;
			}
		}

	} while (end != EOF);

	printf("Result is %d\n", result);

	return 0;

}