#include <stdio.h>

int main() {
	int n, badok[20][20] = {0}, x, y;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		badok[x][y] = 1;
	}
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			printf("%d ", badok[i][j]);
		}
		printf("\n");
	}
}