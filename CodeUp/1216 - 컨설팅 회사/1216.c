#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%d %d %d", &n, &m, &u);
	if(n < m - u) printf("advertise");
	else if (n > m - u) printf("do not advertise");
	else printf("does not matter");
}