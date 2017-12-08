#include<stdio.h>

int main() {
	
	int checksum = 0;
    
	int arr[16];
	int min=0, max=0;
	int len = 0;
    int res;
    
	short end;

	do {
		for (int i = 0; i < 16; i++) {
			end = scanf("%d", &res);
			if (end != EOF) {
    			if (len == 0) {
    			    min = max = res;
    			} else {
    			    if (res < min) {
    			    	min = res;
    			    } 
    			    if (res > max) {
    			    	max = res;
    			    }
    			}
    			len++;
			} else {
			    break;
			}
		}
		if (end != EOF) {
		    len = 0;
	    	checksum += (max - min);
	    	printf("%d %d\n", min, max);
		}
		
	} while (end != EOF);

	printf("Result is %d\n", checksum);

	return 0;

}