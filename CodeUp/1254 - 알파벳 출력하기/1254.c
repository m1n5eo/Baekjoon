#include <stdio.h>

int main() {
	char n, m;
	scanf(" %c %c", &n, &m);
	if(n > m) for(int i = m; i <= n; i++) printf("%c ", i);
	else for(int i = n; i <= m; i++) printf("%c ", i);
}