#include <stdio.h>

int s;

int end(int n) {
	if(n == 1) {
		printf("%d", s-1);
		return 1;
	}
	printf("%d\n", s-n);
	return end(n-1);
}
int main() {
	int n;
	scanf("%d", &n);
	s=n+1;
	end(n);
}