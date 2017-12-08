#include <stdio.h>

#define BANK 16

int is_duplicate(int *bank, int pos, int crc[100000][4]) {

	if (pos == 0) {
		return 0;
	} else {
		for (int i = 0; i < pos; i++) {
			if ((crc[pos][0] == crc[i][0]) &&
				(crc[pos][1] == crc[i][1]) &&
				(crc[pos][2] == crc[i][2]) &&
				(crc[pos][3] == crc[i][3])) {
				    printf("Comparing %d and %d\n", pos, i);
				    printf( "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d \n", bank[0], bank[1], bank[2], bank[3], bank[4], bank[5], bank[6], bank[7], bank[8], bank[9], bank[10], bank[11], bank[12], bank[13], bank[14], bank[15]);
    				return 1;
			}
		}
	}
	return 0;

}

void calculate_crc(int *bank, int crc[100000][4], int pos) {

	for (int i = 0; i < BANK; i++) {
		crc[pos][i/4] |= ((bank[i] & 0xFF) << ((3- i%4)*8));
	}
	//printf("%x %x %x %x\n", crc[pos][0], crc[pos][1], crc[pos][2], crc[pos][3]);

}

int main() {

	int bank[BANK] = {0};
	int crc[100000][4] = {0};
	int idx = 0, end = 0;
	int max = 0, max_idx = 0;
    int val;

	// Scan for inputs
	do {
		end = scanf("%d", &val);
		bank[idx] = val;
		if (val > max) {
			max = val;
			max_idx = idx;
		}
		idx++;
	} while (idx != BANK);

	// Process it
	int steps = 0;
	do {
		int div_val = max / BANK;
		int mod_val = max % BANK;
        bank[max_idx] = 0;
        if (div_val) {
    		for (int i = 0; i < BANK; i++) {
    			if (i == max_idx) {
    				bank[i] += div_val;
    			} else {
    				bank[i] += div_val;
    			}
    		}
        }

		int idx_temp = max_idx+1;
		if (idx_temp >= BANK) {
			idx_temp = 0;
		}
		while (mod_val > 0) {
			bank[idx_temp] += 1;
			idx_temp++;
			if (idx_temp >= BANK) {
				idx_temp = 0;
			}
			mod_val--;
		}
		
		// Get the max
		max = 0;
		max_idx = 0;
		for (int i = 0; i < BANK; i++) {
		    if (bank[i] > max) {
		        max = bank[i];
		        max_idx = i;
		    }
		}
		if (!steps) {
            printf( "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d : %d %d\n", bank[0], bank[1], bank[2], bank[3], bank[4], bank[5], bank[6], bank[7], bank[8], bank[9], bank[10], bank[11], bank[12], bank[13], bank[14], bank[15] , 
                    bank[0] + bank[1] + bank[2] + bank[3] + bank[4] + bank[5] + bank[6] + bank[7] + bank[8] + bank[9] + bank[10] + bank[11] + bank[12] + bank[13] + bank[14] + bank[15], max_idx);
		}
		// Get something like crc.
		calculate_crc(bank, crc, steps);
		steps++;

	} while (!is_duplicate(bank, steps-1, crc));

	printf("Result is %d steps\n", steps);

	return 0;

}