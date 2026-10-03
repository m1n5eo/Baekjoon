#include <stdio.h>
#include <string.h>

int main() {
    char str[111];
    scanf("%s", str);
    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if('a' <= str[i] && str[i] <= 'z') str[i] -= 32;
        else if('A' <= str[i] && str[i] <= 'Z') str[i] += 32;
    }
    printf("%s", str);
}
