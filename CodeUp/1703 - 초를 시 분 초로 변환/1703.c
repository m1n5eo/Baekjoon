#include <stdio.h>

int main() {
	int scan, h, m, s;
	scanf("%d", &scan);
	h = scan/3600;
	scan = scan - (scan/3600) * 3600;
	m = scan/60;
	scan = scan - (scan/60) * 60;
	s = scan;
	printf("%d %d %d", h, m, s);
}