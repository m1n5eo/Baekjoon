#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	int br[n+1][m+1];
	for(int i = 1; i <= n; i++) for(int j = 1; j <= m; j++) scanf("%d", &br[i][j]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			printf("%d ", br[i][j]);
		}
		printf("\n");
	}
}