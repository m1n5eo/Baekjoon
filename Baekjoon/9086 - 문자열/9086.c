#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[1111];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        int str_len = strlen(str);
        printf("%c%c\n", str[0], str[str_len-1]);
    }
}