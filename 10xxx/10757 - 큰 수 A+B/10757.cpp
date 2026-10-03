#include <bits/stdc++.h>
using namespace std;

int k, cnt;
char a[11111], b[11111], dap[11111];

int main() {
    scanf("%s %s", a, b);
    int lena = strlen(a), lenb = strlen(b);
    for(int i = lena>lenb? lena-1:lenb-1; i >= 0; i--) {
        if(a[lena-1] == 0) a[lena-1] = '0';
        else if(b[lenb-1] == 0) b[lenb-1] = '0';
        if(a[lena-1]-48 + b[lenb-1]-48 + k > 9) {
            dap[cnt] = (a[lena-1]-48 + b[lenb-1]-48 + k)%10;
            lena--; lenb--;
            cnt++;
            k = 1;
        }
        else {
            dap[cnt] = (a[lena-1]-48 + b[lenb-1]-48 + k)%10;
            lena--; lenb--;
            cnt++;
            k = 0;
        }
    }
    if(k == 1) printf("1");
    for(int i = cnt-1; i >= 0; i--) {
        printf("%d", dap[i]);
    }
}
