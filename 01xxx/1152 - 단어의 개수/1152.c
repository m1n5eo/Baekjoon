#include <stdio.h>
#include <string.h>

int main() {
    char ch[1000001];
    scanf("%[^\n]s", ch);
    int len = strlen(ch), cnt = 0;
    for(int i = 0; i < len; i++) {
        if(ch[i] == ' ') cnt++;
    }
    if(ch[0] == ' ' && ch[len-1] == ' ') cnt -= 1;
    else if(ch[0] != ' ' && ch[len-1] != ' ') cnt += 1;
    printf("%d", cnt);
}