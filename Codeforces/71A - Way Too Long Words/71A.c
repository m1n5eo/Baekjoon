#include <stdio.h>
#include <string.h>

int main() {
    int n, len;
    char str[111];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        len = strlen(str);
        if(len <= 10) printf("%s\n", str);
        else printf("%c%d%c\n", str[0], len-2, str[len-1]);
    }
}