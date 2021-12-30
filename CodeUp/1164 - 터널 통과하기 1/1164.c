#include <stdio.h>

int main() {
	int turnel[4];
	for(int i = 1; i <= 3; i++) {
		scanf("%d", &turnel[i]);
		if(turnel[i] <= 170) {
			printf("CRASH");
			return 0;
		}
	}
	printf("PASS");
}