#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%d %d %d", &n, &m, &u);
	if(n >= m + u || m >= n + u || u >= m + n) printf("삼각형아님");
	else if(n == m && m == u) printf("정삼각형");
	else if(n == m || m == u || u == n) printf("이등변삼각형");
	else if(n * n + m * m == u * u || n * n + u * u == m * m || u * u + m * m == n * n) printf("직각삼각형");
	else printf("삼각형");
}