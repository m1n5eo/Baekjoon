#include <stdio.h>
#include <string.h>

int main() {
    char str[1111];
    scanf("%s", str);

    int len = strlen(str), cnt = 0;
    for(int i = 0; i < len-3; i++) {
        if(str[i] == 'D' && str[i+1] == 'K' && str[i+2] == 'S' && str[i+3] == 'H') {
            cnt += 1;
        }
    }

    printf("%d", cnt);
}