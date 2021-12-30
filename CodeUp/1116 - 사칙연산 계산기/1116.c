#include <stdio.h>

int main() {
	long long int n, m;
	scanf("%lld %lld", &n, &m);
	printf("%d+%d=%d\n%d-%d=%d\n%d*%d=%d\n%d/%d=%d", n, m, n+m, n, m, n-m, n, m, n*m, n, m, n/m);
}