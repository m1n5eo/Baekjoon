#include <stdio.h>

int main() {
	int n, m, u;
	float g;
	scanf("%d %d %d", &n, &m, &u);
	printf("%d\n", n+m+u);
	g = ((float)n+(float)m+(float)u)/3;
	printf("%.1lf", g);
	return 0;
}