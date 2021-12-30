#include <stdio.h>

int main() {
	int n, m, u;
	double n1, m1, u1;
	scanf("%lf %d %lf %d %lf %d", &n1, &n, &m1, &m, &u1, &u);
	printf("%.1lf", n*n1+m*m1+u*u1);
}