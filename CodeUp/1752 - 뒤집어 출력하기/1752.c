#include <stdio.h>
#include <string.h>

int main() {
	int length;
	char ch[21];
	gets(ch);
	length = strlen(ch);
	for(int i = length-1; i >= 0; i--) {
		printf("%c", ch[i]);
	}
}