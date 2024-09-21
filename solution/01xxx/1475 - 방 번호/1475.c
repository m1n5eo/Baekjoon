#include <stdio.h>
#include <string.h>

int max(int a, int b) {
    if(a > b) return a;
    else return b;
}

int main() {
    char room[11];
    int cnt[11]= {0, };

    scanf("%s", room);

    int len = strlen(room);

    for(int i = 0; i < len; i++) {
        if(room[i]-'0' == 9) cnt[6]++;
        else cnt[room[i]-'0']++;
    }
    
    if(cnt[6]%2 == 0) cnt[6] = cnt[6]/2;
    else cnt[6] = cnt[6]/2+1;

    int set = 0;
    for(int i = 0; i < 9; i++) {
        set = max(set, cnt[i]);
    }
    printf("%d", set);

    return 0;
}