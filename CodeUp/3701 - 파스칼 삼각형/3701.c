#include <stdio.h>

int main() {
	int n;
	long long int arr[55][55];
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(j == 1 || j == n) {
				arr[i][j] = 1;
			}
			else arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
		}
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			printf("%lld ", arr[i][j]);
		}
		printf("\n");
	}
}