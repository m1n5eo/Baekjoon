#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if(n == 0) printf("0");
	else if(n < 0) printf("음수");
	else printf("양수");
}