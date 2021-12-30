#include <stdio.h>

int main() {
	int n, m, arr;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &arr);
		if(arr == m) {
			printf("%d", i);
			break;
		}
		else if(i == n) {
			printf("-1");
		}
	}
}