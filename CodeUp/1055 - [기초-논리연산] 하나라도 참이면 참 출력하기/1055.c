#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if(n == 1 || m == 1) {
		printf("1");
	}
	else {
		printf("0");
	}
}