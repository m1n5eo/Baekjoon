#include <stdio.h>

int main() {
	int sum = 0, n, c = 0;
	scanf("%d", &n);
	while(sum < n) {
		c = c + 1;
		sum = c + sum;
	}
	printf("%d", sum);
}