#include <stdio.h>

int main() {
	int n, m, cnt = 1;
	scanf("%d %d", &n, &m);
	int br[n][m];
	for(int i = n-1; i >= 0; i--) {
		if(n % 2 != 0) {
			if(i % 2 == 0) {
				for(int j = m-1; j >= 0; j--) {
					br[i][j] = cnt;
					cnt += 1;
				}
			}
			else if (i % 2 != 0) {
				for(int j = 0; j < m; j++) {
					br[i][j] = cnt;
					cnt += 1;
				}
			}
		}
		else if(n % 2 == 0) {
			if(i % 2 != 0) {
				for(int j = m-1; j >= 0; j--) {
					br[i][j] = cnt;
					cnt += 1;
				}
			}
			else if (i % 2 == 0) {
				for(int j = 0; j < m; j++) {
					br[i][j] = cnt;
					cnt += 1;
				}
			}
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d ", br[i][j]);
		}
		printf("\n");
	}
}