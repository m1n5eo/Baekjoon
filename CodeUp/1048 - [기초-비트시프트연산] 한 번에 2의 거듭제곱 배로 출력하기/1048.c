#include <stdio.h>

int main() {
	int n, m, g=1;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		g = g*2;
	}
	printf("%d", n*g);
	return 0;
}