#include <stdio.h>

int main() {
    int n, cnt[33] = {0, };
    char name[33];

    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", name);
        cnt[name[0]-'a']++;
    }

    int sw = 0;
    for(int i = 0; i < 26; i++) {
        if(cnt[i] > 4) {
            printf("%c", i+'a');
            sw = 1;
        }
    }
    if(sw == 0) printf("PREDAJA");

    return 0;
}