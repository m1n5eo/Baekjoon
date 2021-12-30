#include <stdio.h>

int main() {
    int i = 0;
	char ch[100];
	gets(ch);
	while(1) {
        if(ch[i] == '\0') break;
        else if(ch[i] != ' ') printf("%c", ch[i]);
        i = i + 1;
	}
}