#include <stdio.h>
#include <string.h>

int main() {
    char str[111];
    scanf("%[^\n]s", str);

    int len = strlen(str);
    for(int i = 0; i < len; i++) {
        if('a' <= str[i] && str[i] <= 'm') {
            str[i] += 13;
        }
        else if('n' <= str[i] && str[i] <= 'z') {
            str[i] -= 13;
        }
        else if('A' <= str[i] && str[i] <= 'M') {
            str[i] += 13;
        }
        else if('N' <= str[i] && str[i] <= 'Z') {
            str[i] -= 13;
        }
        else continue;
    }

    printf("%s", str);
}