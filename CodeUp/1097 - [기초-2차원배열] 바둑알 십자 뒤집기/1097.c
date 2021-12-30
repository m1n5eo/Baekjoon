#include <stdio.h>

int main() {
	int badok[20][20];
	int n;
	for(int i = 1; i <= 19; i++) {
		for(int j = 1; j <= 19; j++) {
			scanf("%d ", &badok[i][j]);
		}
	}
	scanf("%d", &n);
	int x[n+1], y[n+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &x[i], &y[i]);
	}
	for(int i = 1; i <= 19; i++){
		for (int j = 1; j <= n; j++) {
			badok[x[j]][i] = 1-badok[x[j]][i];
		}
	}
	for(int i = 1; i <= 19; i++){
		for (int j = 1; j <= n; j++) {
			badok[i][y[j]] = 1-badok[i][y[j]];
		}
	}
	for(int i = 1; i <= 19; i++) {
		for(int j = 1; j <= 19; j++) {
			printf("%d ", badok[i][j]);
		}
		printf("\n");
	}
}