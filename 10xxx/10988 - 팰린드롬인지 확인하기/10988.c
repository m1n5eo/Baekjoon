#include <stdio.h>
#include <string.h>

int main() {
    char str[111];
    scanf("%s", str);
    int len = strlen(str), cnt = 0;
    for(int i = 0; i < len/2; i++) {
        if(str[i] == str[len-i-1]) {
            cnt++;
        }
    }
    if(cnt == len/2) printf("1");
    else printf("0");
}