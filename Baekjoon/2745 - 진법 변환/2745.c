#include <stdio.h>
#include <string.h>

int main() {
    char str[111];
    int n, len, sum = 0;
    scanf("%s %d", str, &n);
    len = strlen(str);
    for(int i = 0; i < len; i++) {
        int temp = 1;
        for(int j = 0; j < len-i-1; j++) {
            temp *= n;
        }
        if('A' <= str[i] && str[i] <= 'Z') sum += temp*((int)str[i]-55);
        else if('0' <= str[i] && str[i] <= '9') sum += temp*((int)str[i]-48);
    }
    printf("%d", sum);
}
