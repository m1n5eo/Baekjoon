#include <stdio.h>
#include <string.h>

int main() {
    int len, sum = 0;
    char ch[7];
    gets(ch);
    len = strlen(ch);
    for(int i = len-1; i >= 0; i--) {
        if(ch[i] == '0') len = len - 1;
        else break;
    }
    for(int i = len-1; i >= 0; i--) {
        if(ch[i] != '0' || (len-1 != i && i != 0)) {
            printf("%c", ch[i]);
        }
        sum = sum + ch[i]-48;
    }
    printf("\n%d", sum);
}