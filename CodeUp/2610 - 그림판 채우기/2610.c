#include <stdio.h>

char paint[22][22];

void dfs(int xx, int yy) {
	if(xx < 0 || yy < 0 || xx > 9 || yy > 9) return;
	else if(paint[xx][yy] == '*') return;
	paint[xx][yy] = '*';
	dfs(xx+1, yy);
	dfs(xx-1, yy);
	dfs(xx, yy+1);
	dfs(xx, yy-1);
} 

int main() {
	int x, y;
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			scanf(" %c", &paint[i][j]);
		}
	}
	scanf("%d %d", &y, &x);
	
	dfs(x, y);
	
	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			printf("%c", paint[i][j]);
		}
		printf("\n");
	}
}