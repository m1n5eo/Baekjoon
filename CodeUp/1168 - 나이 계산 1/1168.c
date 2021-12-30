#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if(m == 1 || m == 2) n = (n / 10000) + 1900;
	else n = (n / 10000) + 2000;
	n = 2012 - n + 1;
	printf("%d", n);
}