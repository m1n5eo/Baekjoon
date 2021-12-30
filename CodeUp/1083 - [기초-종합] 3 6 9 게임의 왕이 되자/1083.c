#include <stdio.h>

int main() {
	int n, m;
	scanf("%X", &n);
	for(int i = 1; i <= n; i++) {
		if(i%3==0) {
			printf("X ");
		}
		else {
			printf("%d ", i);
		}
	}
	return 0;
}