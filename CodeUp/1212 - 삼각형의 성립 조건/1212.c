#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%d %d %d", &n, &m, &u);
	if(n >= m && n >= u && n < m + u) printf("yes");
	else if(m >= n && m >= u && m < n + u) printf("yes");
	else if(u >= m && u >= n && u < m + n) printf("yes");
	else printf("no");
}