#include <stdio.h>
#include <string.h>

int main() {

	int result = 0;
	char ch;
	char arr[20][256];
	int count[20];
	int mask_word[20];
	int size = 0;
	int i = 0;
	int duplicate = 0;
	int end = 0;
	int same = 0;

	// Mask
	do {
		i = 0;
		duplicate = 0;
		do {
			end = scanf("%c", &ch);
			if (ch != ' ') {
				count[i] = count[i] + 1;
				mask_word[i] = mask_word[i] | (1 << (ch - 'a'));
				same = 0;
			} else {
				// Skip and increment i
				if (!same) {
					i++;
					same = 1;
				}
			}
		} while (ch != '\n' && end != EOF);

		if (end != EOF) {
    		for (int j = 0; j < i - 1; j++) {
    			for (int k = j + 1; k < i; k++) {
    				if ((mask_word[j] == mask_word[k]) && (count[j] == count[k])) {
    					duplicate = 1;
    					break;
    				}
    			}
    		}
    
    		if (!duplicate) {
    			result++;
    		}
        }

	} while (end != EOF);

	printf("Result is %d\n", result);


	return 0;
}