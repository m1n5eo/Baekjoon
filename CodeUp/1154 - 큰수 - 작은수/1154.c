#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (n < m) printf("%d", m-n);
	else printf("%d", n-m);
}