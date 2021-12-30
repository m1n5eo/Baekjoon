#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	if (n <= 10) printf("정상");
	else if (n <= 20) printf("과체중");
	else printf("비만");
}