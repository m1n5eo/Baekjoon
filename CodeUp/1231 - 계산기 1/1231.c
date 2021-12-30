#include <stdio.h>

int main() {
	long long int n, m;
	char ch;
	scanf("%lld%c%lld", &n, &ch, &m);
	if(ch == '+') printf("%lld", n + m);
	else if(ch == '-') printf("%lld", n - m);
	else if(ch == '*') printf("%lld", n * m);
	else if(ch == '/') printf("%.2lf", (float)n / m);
}