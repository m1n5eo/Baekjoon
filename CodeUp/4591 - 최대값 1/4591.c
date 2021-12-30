#include <stdio.h>
 
int main() {
    int ki[10], max = -1, max_idx;
    for(int i = 1; i <= 9; i++) {
    	scanf("%d", &ki[i]);
	}
	
	for(int i = 1; i <= 9; i++) {
		if(ki[i] > max) {
			max = ki[i];
			max_idx = i;
		}
	}
	printf("%d\n%d", max, max_idx);
}