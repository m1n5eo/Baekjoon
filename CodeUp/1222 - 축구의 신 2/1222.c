#include <stdio.h>

int main() {
	int n, one, two;
	scanf("%d %d %d", &n, &one, &two);
	while(n < 90) {
		n = n + 5;
		one = one + 1;
	}
	if(one < two) printf("lose");
	else if(one > two) printf("win");
	else printf("same");
}