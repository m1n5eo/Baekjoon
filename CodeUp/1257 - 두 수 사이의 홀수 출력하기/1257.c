#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if(n % 2 == 0) n = n + 1;
	for(int i = n; i <= m; i=i+2) printf("%d ", i);
}