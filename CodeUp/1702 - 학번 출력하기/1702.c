#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%d %d %d", &n, &m, &u);
	if(m % 2 == 0) printf("%d%d%d %d%d%d", n, m, u, n, m, u);
	else if(m % 2 != 0) printf("%d%d%d", n, m, u);
}