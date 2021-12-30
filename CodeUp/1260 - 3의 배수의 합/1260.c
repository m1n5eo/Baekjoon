#include <stdio.h>

int main() {
	int n, m, sum = 0;
	scanf("%d %d", &n, &m);
	if(n % 3 != 0) n = (n - n % 3) + 3;
	for(int i = n; i <= m; i=i+3) sum = sum + i;
	printf("%d", sum);
}