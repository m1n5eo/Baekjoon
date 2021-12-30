#include <stdio.h>

int main() {
	char sad[10][10];
	int scan[10], n = 0;
	for(int i = 0; i < 10; i++) {
		scanf("%d", &scan[i]);
		for(int j = 0; j < 10; j++) {
			sad[i][j] = ' ';
		}
	}

	for(int i = 0; i < 10; i++) {
		n = scan[i] / 10;
		for(int j = 0; j < n; j++) {
			sad[j][i] = '#';
		}
	}

	for(int i = 9; i >= 0; i--) {
		for(int j = 0; j < 10; j++) {
			printf("%c ", sad[i][j]);
		}
		printf("\n");
	}
}