#include <stdio.h>

int main() {
    int len;
    char str[111111];

    scanf("%d", &len);
    scanf("%s", str);

    for(int i = len-5; i < len; i++) {
        printf("%c", str[i]);
    }

    return 0;
}