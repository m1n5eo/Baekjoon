#include <stdio.h>

int main() {
	int n, m, check;
	scanf("%d %d %d", &n, &m, &check);
	for(int i = n; i <= check; i=i+m-n) {
		printf("%d ", i);
	}
}