#include <stdio.h>

int main() {
	int n, m;
	double sum;
	scanf("%d %d", &n, &m);
	sum = (double)(n*m)/2;
	printf("%.1lf", sum);
}