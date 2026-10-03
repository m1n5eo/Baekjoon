#include <bits/stdc++.h>
using namespace std;

int check(int idx) {
    int i = 0;
    char str[100001];
    while(idx) {
        str[i++] = idx%10+48;
        idx = idx/10;
    }
    int len = strlen(str);
    for(int i = 2; i < len; i++) {
        if(str[i-2] == '6' && str[i-1] == '6'&& str[i] == '6') return 1;
    }
    return 0;
}

int main() {
    int n, i, cnt = 0;
    scanf("%d", &n);
    for(i = 1; cnt != n; i++) {
        if(check(i)) cnt++;
    }
    printf("%d", i-1);
}
