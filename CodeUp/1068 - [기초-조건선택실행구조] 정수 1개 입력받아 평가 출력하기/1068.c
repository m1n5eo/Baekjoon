#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if(n >= 90) printf("A");
	else if(n >= 70) printf("B");
	else if(n >= 40) printf("C");
	else printf("D");
}