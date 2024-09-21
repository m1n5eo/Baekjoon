#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sw, cnt = 0, check[33];
    char ch[111];

    scanf("%d", &n);
    for(int t = 0; t < n; t++) {
        scanf("%s", ch);
        int len = strlen(ch);
        sw = 1;
        for(int i = 0; i < 33; i++) check[i] = 0;
        for(int i = 0; i < len; i++) {
            if(!check[ch[i]-97]) {
                check[ch[i]-97] = i+1;
                sw = 1;
                continue;
            }
            else {
                if(check[ch[i]-97] == i) {
                    check[ch[i]-97] = i+1;
                    sw = 1;
                    continue;
                }
                else {
                    sw = 0;
                    break;
                }
            }
        }
        if(sw == 0) continue;
        cnt = cnt + 1;
    }
    printf("%d", cnt);
}