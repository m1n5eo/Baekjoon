#include <stdio.h>

int yes(int a, int b) {
	if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) printf("31");
	else if (b == 2) printf("29");
	else printf("30");
}

int no(int a, int b) {
	if(b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10 || b == 12) printf("31");
	else if (b == 2) printf("28");
	else printf("30");
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if(n % 4 == 0 && n % 100 != 0) yes(n, m);
	else if(n % 400 == 0) yes(n, m);
	else no(n, m);
}