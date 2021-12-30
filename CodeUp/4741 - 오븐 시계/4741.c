#include <stdio.h>

int main() {
	int a, b, c, k;
	scanf("%d %d %d", &a, &b, &c);
	
	b = b + c;
	if(b >= 60) {
		k = b/60;
		b = b - 60*k;
		a = a + k;
	}
	
	if(a >= 24) {
		a = a - 24;
	}
	
	printf("%d %d", a, b);
}