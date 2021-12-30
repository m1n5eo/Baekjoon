#include <stdio.h>

int main() {
	float n, m, o, p;
	scanf("%f %f %f %f", &n, &m, &o, &p);
	if(n / m > o / p) printf(">");
	else if(n / m < o / p) printf("<");
	else printf("=");
}