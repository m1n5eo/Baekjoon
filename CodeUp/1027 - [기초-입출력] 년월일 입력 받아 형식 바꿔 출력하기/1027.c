#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%04d.%02d.%02d", &n, &m, &u);
	printf("%02d-%02d-%04d", u, m, n);
}