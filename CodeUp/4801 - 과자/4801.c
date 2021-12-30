#include <stdio.h>

int main() {
	int n, m, money, print;
	scanf("%d %d %d", &n, &m, &money);
	print = n*m - money;
	if(print < 0) print = 0;
	printf("%d", print);
}