#include <stdio.h>

int main() {
	int n, m, u;
	scanf("%d %d %d", &n, &m, &u);
	if(n < m && n < u) {
		printf("%d", n);
	}
	else if (m < n && m < u){
		printf("%d", m);
	}
	else {
		printf("%d", u);
	}
}