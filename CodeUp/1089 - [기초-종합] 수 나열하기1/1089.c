#include <stdio.h>

int main() {
	int a, d, n, sum = 0;
	scanf("%d %d %d", &a, &d, &n);
	sum = a;
	for(int i = 2; i <= n; i++) {
		sum = sum + d;
	}
	printf("%d", sum);
}