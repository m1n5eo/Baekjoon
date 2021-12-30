#include <stdio.h>

int main() {
	int a, b, c, d, r, k;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	
	c = c + d;
	if(c >= 60) {
		k = c/60;
		c = c - 60*k;
		b = b + k;
	}
	
	if(b >= 60) {
		k = b/60;
		b = b - 60*k;
		a = a + k;
	}
	
	if(a >= 24) {
		k = a/24;
		a = a - 24*k;
	}
	
	printf("%d %d %d", a, b, c);
}