#include <stdio.h>

int main() {
	int number[11];
	for(int i = 1; i <= 10; i++) scanf("%d", &number[i]);
	for(int i = 1; i <= 10; i++) {
		if(number[i] % 5 == 0) {
			printf("%d", number[i]);
			return 0;
		}
	}
	printf("0");
}