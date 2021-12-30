#include <stdio.h>

int main() {
	int n, a;
	scanf("%d", &n);
	int sum[25] = {0};
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a);
		sum[a] = sum[a] + 1;
	}
	for(int i = 1; i <= 23; i++) {
		printf("%d ", sum[i]);
	}
}