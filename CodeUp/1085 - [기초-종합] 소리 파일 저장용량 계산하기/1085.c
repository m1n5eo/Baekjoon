#include <stdio.h>

int main() {
	int h, b, c, s;
	double a, sum;
	scanf("%d %d %d %d", &h, &b, &c, &s);
	sum = h*b*c*s;
	a = sum/8/1024/1024;
	printf("%.1lf MB", a);
}