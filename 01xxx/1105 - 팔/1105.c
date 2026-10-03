#include <stdio.h>
#include <string.h>

int main() {
    char n[22], m[22];
    scanf("%s %s", n, m);
    if(strlen(n) != strlen(m)) {
        printf("0");
        return 0;
    }
    int cnt = 0;
    for(int i = 0; i < strlen(n); i++) {
        if(n[i] == m[i] && n[i] == '8') cnt++;
        else if(n[i] != m[i]) break;
    }
    printf("%d", cnt);
}