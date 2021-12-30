#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	n = 2012 - n + 1;
	if(n / 100 == 19) printf("%d %d", n%100, 1);
	else printf("%d %d", n%100, 3);
}