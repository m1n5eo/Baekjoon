#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%d %d %d", &n, &m, &u);
	if(n <= 170) printf("CRASH %d", n);
	else if(m <= 170) printf("CRASH %d", m);
	else if(u <= 170) printf("CRASH %d", u);
	else printf("PASS");
}