#include <stdio.h>

int main() {
	int n, m, cnt = 1, br[100][100];
	scanf("%d %d", &n, &m);
	for(int i = m-1; i >= 0; i--) {
		if(m % 2 == 0) {
			if(i % 2 != 0) {
				for(int j = n-1; j >= 0; j--) {
					br[j][i] = cnt;
					cnt += 1;
				}
			}
			else if(i % 2 == 0) {
				for(int j = 0; j < n; j++) {
					br[j][i] = cnt;
					cnt += 1;
				}
			}
		}
		else if(m % 2 != 0) {
			if(i % 2 == 0) {
				for(int j = n-1; j >= 0; j--) {
					br[j][i] = cnt;
					cnt += 1;
				}
			}
			else if(i % 2 != 0) {
				for(int j = 0; j < n; j++) {
					br[j][i] = cnt;
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