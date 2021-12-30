#include <stdio.h>

int main() {
    int cnt = 0;
    char ch[100];
    gets(ch);
    for(int i = 0; i < 100; i++) {
        if(ch[i] != '\0') cnt = cnt + 1;
        else break;
    }

    for(int i = cnt-1; i >= 0; i--) {
        printf("%c", ch[i]);
    }
}