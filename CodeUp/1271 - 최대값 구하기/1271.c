#include <stdio.h>

int main() {
	int n, max = 0;
	scanf("%d", &n);
	int num[n+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d", &num[i]);
		if(num[i] > max) max = num[i];
	}
	printf("%d", max);
}