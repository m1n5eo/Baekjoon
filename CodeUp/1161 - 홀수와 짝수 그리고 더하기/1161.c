#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	n = n % 2;
	m = m % 2;
	if(n == 0) printf("짝수+");
	else printf("홀수+");
	if(m == 0) printf("짝수=");
	else printf("홀수=");
	n = (n + m) % 2;
	if(n == 0) printf("짝수");
	else printf("홀수");
}