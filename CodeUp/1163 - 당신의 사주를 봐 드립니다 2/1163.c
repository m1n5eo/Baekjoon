#include <stdio.h>

int main() {
	int y, m, d, sum;
	scanf("%d %d %d", &y, &m, &d);
	sum = y + m + d;
	sum = sum / 100;
	if(sum % 2 == 0) printf("대박");
	else printf("그럭저럭");
}