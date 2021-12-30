#include <stdio.h>

int main() {
	int m1, m2, m3, c = 2;
	scanf("%d %d %d", &m1, &m2, &m3);
	while(1) {
		while(c % m1 == 0 && c % m2 == 0 && c % m3 == 0) {
			printf("%d", c);
			return 0;
		}
		c = c + 1;
	}
}