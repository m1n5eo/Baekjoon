#include <stdio.h>

int main() {
	char n;
	int i;
	char ch[20];
    scanf("%s", ch);
    for(i = 0; ch[i] != '\0'; i++) printf("%c", ch[i]+2);
    printf("\n");
    for(i = 0; ch[i] != '\0'; i++) printf("%c",(ch[i]*7)%80+48);
}