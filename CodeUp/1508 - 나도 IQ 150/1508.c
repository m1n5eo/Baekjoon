#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int br[n+1][n+1];
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			br[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) scanf("%d", &br[i][1]);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= i; j++) {
			if(br[i][j] == 0) {
				br[i][j] =  br[i][j-1] - br[i-1][j-1];
			}
			printf("%d ", br[i][j]);
		}
		printf("\n");
	}
}