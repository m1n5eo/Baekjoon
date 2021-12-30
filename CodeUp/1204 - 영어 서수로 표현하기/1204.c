#include <stdio.h>

int main() {
	int n, m;
	scanf("%d", &n);
	if (n / 10 == 1) printf("%dth", n);
	else if (n % 10 == 1) printf("%dst", n);
	else if (n % 10 == 2) printf("%dnd", n);
	else if (n % 10 == 3) printf("%drd", n);
	else printf("%dth", n);
}