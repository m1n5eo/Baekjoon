#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char str[55][55], print[55];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%s", str[i]);
    int len = strlen(str[0]);
    for(int i = 0; i < len; i++) {
        int cnt = 0;
        for(int j = 0; j < n-1; j++) {
            if(str[j][i] == str[j+1][i]) cnt++;
        }
        if(cnt == n-1) print[i] = str[0][i];
        else print[i] = '?';
    }
    for(int i = 0; i < len; i++) printf("%c", print[i]);
}