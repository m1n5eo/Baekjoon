#include <stdio.h>

int end(int n) {
	if(n == 1) {
		printf("1");
		return 1;
	}
	printf("%d\n", n);
	return end(n-1);
}
int main() {
	int n;
	scanf("%d", &n);
	end(n);
}