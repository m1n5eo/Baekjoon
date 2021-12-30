#include <stdio.h>
 
int main() {
	int w, h, n, c = 0;
	scanf("%d %d %d", &w, &h, &n);
	int l[n+1], d[n+1], x[n+1], y[n+1], stick[w+1][h+1];
	for(int i = 1; i <= n; i++) {
		scanf("%d %d %d %d", &l[i], &d[i], &x[i], &y[i]);
	}
	for(int i = 1; i <= w; i++) {
		for(int j = 1; j <= h; j++) {
			stick[i][j] = 0;
		}
	}
	for(int i = 1; i <= n; i++) {
		c = 0;
		if(d[i] == 0) {
			while(l[i] > c) {
				stick[x[i]][y[i]+c]= 1;
				c = c + 1;
			}
		}
		else {
			while(l[i] > c) {
				stick[x[i]+c][y[i]]= 1;
				c = c + 1;
			}
		}
	}
	for (int i = 1; i <= w; i++) {
		for (int j = 1; j <= h; j++) {
			printf("%d ", stick[i][j]);
		}
		printf("\n");
	}
	return 0;
}