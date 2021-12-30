#include <stdio.h>

int main() {
    int cnt = 0;
    char ch[100];
    gets(ch);
    for(int i = 0; i < 100; i++) {
        if(ch[i] == '\0') {
            printf("%d", cnt);
            return 0;
        }
        else if (ch[i] == 'l' && ch[i+1] == 'o' && ch[i+2] == 'v' && ch[i+3] == 'e') cnt = cnt + 1;
    }
}