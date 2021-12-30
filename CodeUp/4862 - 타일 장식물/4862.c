#include <stdio.h>

long long int fibo[83];

int main() {
	int n;
	scanf("%d", &n);
	fibo[0] = fibo[1] = 1;
	
	for(int i = 2; i <= n; i++) fibo[i] = fibo[i-1] + fibo[i-2];
	
	printf("%lld", (fibo[n]+fibo[n-1])*2);
}