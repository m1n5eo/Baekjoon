#include <stdio.h>

int main() {
	int temp, ki[8];
	
	for(int i = 1; i <= 7; i++) {
		scanf("%d", &ki[i]);
		for(int j = 1; j <= i; j++) {
			if(ki[i] >= ki[j]) {
				temp = ki[i];
				ki[i] = ki[j];
				ki[j] = temp;
			}
		}
	}
	
	printf("%d\n%d", ki[1], ki[2]);
}