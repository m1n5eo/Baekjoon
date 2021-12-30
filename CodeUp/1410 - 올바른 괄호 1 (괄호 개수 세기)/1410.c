#include <stdio.h>

int main() {
    int n = 0, m = 0, i = 0;
	char ch[100000];
	gets(ch);
	while(ch[i] != '\0') {
        if(ch[i] == '(') n = n + 1;
        else if(ch[i] == ')') m = m + 1;
        i = i + 1;
	}
	printf("%d %d", n, m);
}