#include <stdio.h>

int main() {
	int n, m, a, b, c;
	scanf("%01d%01d%01d%01d%01d", &n, &m, &a, &b, &c);
	printf("[%d]\n[%d]\n[%d]\n[%d]\n[%d]", n*10000, m*1000, a*100, b*10, c);
	return 0;
}