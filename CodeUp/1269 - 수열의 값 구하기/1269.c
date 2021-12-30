#include <stdio.h>

int main() {
	int a, b, c, n, hang;
	scanf("%d %d %d %d", &a, &b, &c, &n);
	for(int i = 2; i <= n; i++) a = a * b + c;
	printf("%d", a);
}