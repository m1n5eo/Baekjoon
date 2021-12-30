#include <stdio.h>

int main() {
	int n, m, c = 1;
	scanf("%d %d", &n, &m);
	int data[n+1][m+1];
	for(int i = n; i >= 1; i--) {
		for(int j = m; j >= 1; j--) {
			data[i][j] = c;
			c++;
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
}