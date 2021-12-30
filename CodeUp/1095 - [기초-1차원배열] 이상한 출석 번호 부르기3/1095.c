#include <stdio.h>

int main() {
	int n, a, qlry = 40;
	scanf("%d", &n);
	int sum[n+1];
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a);
		if(qlry > a) {
			qlry = a;
		}
	}
	printf("%d", qlry);
}