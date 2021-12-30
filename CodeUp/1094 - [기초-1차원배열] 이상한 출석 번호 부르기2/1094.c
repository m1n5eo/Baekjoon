#include <stdio.h>

int main() {
	int n, a;
	scanf("%d", &n);
	int sum[n+1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		sum[i] = a;
	}
	for(int j = n; j >= 1; j--) {
		printf("%d ", sum[j]);
	}
}