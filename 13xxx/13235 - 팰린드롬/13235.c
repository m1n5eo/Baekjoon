#include <stdio.h>
#include <string.h>

int main() {
    char str[22];
    scanf("%s", str);

    int len = strlen(str), sw = 1;
    for(int i = 0; i < len/2; i++) {
        if(str[i] == str[len-i-1]) continue;
        else sw = 0;
    }

    if(sw == 1) printf("true");
    else printf("false");

    return 0;
}