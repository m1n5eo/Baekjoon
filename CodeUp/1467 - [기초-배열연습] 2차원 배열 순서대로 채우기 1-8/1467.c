#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int data[n+1][m+1], c = 1;
	
	for(int i = m; i >= 1; i--) {
		for(int j = 1; j <= n; j++) {
			data[j][i] = c;
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