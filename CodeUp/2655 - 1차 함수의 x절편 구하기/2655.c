#include <stdio.h>

int main() {
	int n, m;
	double dap;
	scanf("%d %d", &n, &m);
	dap = -((double)m/n);
	printf("%.4lf", dap);
}