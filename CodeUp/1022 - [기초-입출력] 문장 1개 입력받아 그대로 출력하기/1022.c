#include <stdio.h>

int main() {
	char ch[2001];
	fgets(ch, 2000, stdin);
	printf("%s", ch);
	return 0;
}