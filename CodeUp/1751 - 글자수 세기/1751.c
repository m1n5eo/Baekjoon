#include <stdio.h>
#include <string.h>

int main() {
	char ch[2001];
	gets(ch);
	int n;
	n = strlen(ch);
	printf("%d", n); 
}