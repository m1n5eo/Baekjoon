#include <stdio.h>

int main() {
	int a, m, d, n, sum = 0;
	scanf("%d %d %d %d", &a, &m, &d, &n);
	sum = a;
	for(int i = 2; i <= n; i++) {
		sum = sum * m + d;
	}
	printf("%d", sum);
}