#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, chk[81];
    char ch[81];
    scanf("%d", &t);
    for(int testcase = 0; testcase < t; testcase++) {
        scanf("%s", ch);
        int len = strlen(ch);
        if(ch[0] == 'O') chk[0] = 1;
        else if(ch[0] == 'X') chk[0] = 0;
        for(int i = 1; i < len; i++) {
            if(ch[i] == 'X') chk[i] = 0;
            else if(ch[i] == 'O') {
                if(ch[i-1] == 'O') chk[i] = chk[i-1]+1;
                else if(ch[i-1] == 'X') chk[i] = 1;
            }
        }
        int cnt = 0;
        for(int i = 0; i < len; i++) {
            cnt = cnt+chk[i];
        }
        printf("%d\n", cnt);
    }
}
