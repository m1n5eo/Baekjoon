#include <stdio.h>

int main() {
	double n, m, good, dap;
	scanf("%lf %lf", &n, &m);
	good = (n - 100) * 0.9;
	dap = (m - good) * 100 / good;
	if(dap <= 10) printf("정상");
	else if(dap > 10 && dap <= 20) printf("과체중");
	else printf("비만");
}