#include <stdio.h>

int main() {
	int n, m, sum = 0;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%1d", &m);
		sum = sum + m;
	}
	printf("%d", sum);
}
