#include <stdio.h>

int main() {
	long long int n;
	scanf("%lld", &n);
	for(long long int i = 1; i <= n; i++) {
		for(long long int j = 0; j < n; j++) {
			printf("%lld ", i*n-j);
		}
		printf("\n");
	}
}