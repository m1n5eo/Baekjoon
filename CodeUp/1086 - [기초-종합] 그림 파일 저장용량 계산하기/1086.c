#include <stdio.h>

int main() {
	int w, h, b;
	double a, sum;
	scanf("%d %d %d", &w, &h, &b);
	sum = w*h*b;
	a = sum/8/1024/1024;
	printf("%.2f MB", a);
}