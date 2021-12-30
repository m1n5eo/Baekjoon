#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	if (m >= 30) m = m - 30;
	else if(m < 30) {
		m = m - 30;
		m = 60 - -m;
		if(n == 0) n = 23;
		else if (n > 0) n = n - 1;
	}
	printf("%d %d", n, m);
}