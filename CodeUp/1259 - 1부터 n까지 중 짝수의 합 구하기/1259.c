#include <stdio.h>

int main() {
	long long int n, sum = 0;
	scanf("%lld", &n);
	for(int i = 2; i <= n; i=i+2) sum = sum + i;
	printf("%d", sum);
}