#include <stdio.h>

int main() {
	int i, j, n, k;
	scanf("%d %d", &n, &k);
	int m = k;
	for (i = 1; i <= n; i++) {
		if (m < 0) m = k-1;
		for (j = 1; j <= n; j++) {
			if (i == 1 || i == n) printf("*");
			else if (j == 1 || j == n || j % k == m) printf("*");
			else printf(" ");
		}
		--m;
		printf("\n");
	}
}