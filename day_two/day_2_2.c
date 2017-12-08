#include<stdio.h>

int main() {
	
	int checksum = 0;
    
	int arr[16];
	int min=0, max=0;
	int len = 0;
    int res;
    
	short end;


	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			end = scanf("%d", &res);
			arr[j] = res;
		}
		// Check the mod possibility
		// 
		for(int ko = 0; ko < 15; ko++) {
			for (int ki = ko + 1; ki < 16; ki++) {
				if ((arr[ko] % arr[ki] == 0)) {
					checksum += (arr[ko] / arr[ki]);
				} else if (arr[ki] % arr[ko] == 0) {
					checksum += (arr[ki] / arr[ko]);
				}
			}
		}
		len = 0;
	}

	printf("Result is %d\n", checksum);

	return 0;

}