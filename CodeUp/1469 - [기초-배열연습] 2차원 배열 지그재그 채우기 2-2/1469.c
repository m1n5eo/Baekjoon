#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	int data[n+1][n+1], c = 1;
	for(int i = 1; i <= n; i++) {
		if(i % 2 == 0) {
			for(int j = 1; j <= n; j++) {
				data[i][j] = c;
				c++;
			}
		}
		else if(i % 2 != 0) {
			for(int j = n; j >= 1; j--) {
				data[i][j] = c;
				c++;
			}
		}
	}
	
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
}