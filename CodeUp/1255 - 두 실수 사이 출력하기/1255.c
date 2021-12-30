#include <stdio.h>

int main() {
	double n, m;
	scanf("%lf %lf", &n, &m);
	if(n < m) for(double i = n; i <= m; i=i+0.01) printf("%.2lf ", i);
	else for(double i = m; i <= n; i=i+0.01) printf("%.2lf ", i);
}