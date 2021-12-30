#include <stdio.h>

int main() {
	int n,m;
	scanf("%d %d", &n, &m);
	printf("%d + %d = %d\n%d - %d = %d\n%d * %d = %d\n%d / %d = %d\n%d %% %d = %d", n, m, n+m, n, m, n-m, n, m, n*m, n, m, n/m, n, m, n%m);
}