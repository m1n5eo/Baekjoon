#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	printf("%d\n%d\n%d\n%d\n%d\n%.2f", n+m, n-m, n*m, n/m, n%m, (float)n/m);
}