#include <stdio.h>

int main() {
	long long int n, c = 1;
	scanf("%lld", &n);
	long long int bae[n+1][n+1];
	for(long long int i = 1; i <= n; i++) {
		for(long long int j = n; j >= 1; j--) {
			bae[i][j] = c;
			c++;
		}
	}
	
	for(long long int i = 1; i <= n; i++) {
		for(long long int j = 1; j <= n; j++) {
			printf("%lld ", bae[j][i]);
		}
		printf("\n");
	}
}