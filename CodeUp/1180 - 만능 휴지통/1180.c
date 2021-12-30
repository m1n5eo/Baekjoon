#include <stdio.h>

int main() {
	int n, m;
	scanf("%01d%01d", &n, &m);
	n = (m*10+n)*2%100;
	if(n <= 50) printf("%d\nGOOD", n);
	else printf("%d\nOH MY GOD", n);
}