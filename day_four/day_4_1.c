#include <stdio.h>
#include <string.h>

int main() {

	int result = 0;
	char ch;
	char arr[20][256];
	int size = 0;
	int i = 0;
	int duplicate = 0;
	int end = 0;

	// Scan per line
	do {
        duplicate = 0;
		do {
			end = scanf("%s%c", arr[i], &ch);
			i++;
			printf("Scanning %s, %d, %c\n", arr[i-1], end, ch);
		} while (ch != '\n' && end != EOF);

        if (end != EOF) {
    		for (int j = 0; j < i - 1; j++) {
    			for (int k = j + 1; k < i; k++) {
    				if (strcmp(arr[j], arr[k]) == 0) {
    					duplicate = 1;
    					break;
    				}
    			}
    		}
    
    		if (!duplicate) {
    			result++;
    		}
        }

		// Scan all words in the row
	} while(end != EOF) ;

	printf("Result is %d\n", result);


	return 0;
}