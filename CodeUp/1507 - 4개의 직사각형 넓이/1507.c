#include <stdio.h>

int land[103][103];

int main() {
	int x1, y1, x2, y2, cnt = 0;
	for(int i = 0; i < 4; i++) {
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		for(int j = x1; j < x2; j++) {
			for(int k = y1; k < y2; k++) {
				land[j][k] = 1;
			}
		}
	}
	
	for(int i = 0; i <= 100; i++) {
		for(int j = 0; j <= 100; j++) {
			cnt = cnt + land[i][j];
		}
	}
	
	printf("%d", cnt);
}