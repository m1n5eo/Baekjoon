#include <stdio.h>

int main() {
	int n, m, u;
	double sum;
	scanf("%d %d %d", &n, &m, &u);
	sum = (double)(n+m+u)/3;
	printf("%.2lf",  sum);
}