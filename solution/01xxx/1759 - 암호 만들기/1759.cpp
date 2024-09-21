#include <bits/stdc++.h>
using namespace std;

int l, c, apb[16], dap[16], check_mj[16];

void f(int idx, int apbl, int mo_cnt, int ja_cnt) {
    if(idx == l) {
        if(mo_cnt >= 1 && ja_cnt >= 2) {
            for(int i = 0; i < l; i++) printf("%c", dap[i]);
            printf("\n");
            return;
        }
        else return;
    }
    else {
        for(int i = apbl+1; i < c; i++) {
            dap[idx] = apb[i];
            if(check_mj[i] == 1) f(idx+1, i, mo_cnt+1, ja_cnt);
            else f(idx+1, i, mo_cnt, ja_cnt+1);
        }
    }
    return;
}

int main() {
    scanf("%d %d", &l, &c);
    for(int i = 0; i < c; i++) {
        scanf(" %c", &apb[i]);
    }
    sort(apb, apb+c);
    for(int i = 0; i < c; i++) {
        if(apb[i] == 'a' || apb[i] == 'e' || apb[i] == 'i' || apb[i] == 'o' || apb[i] == 'u') {
            check_mj[i] = 1;
        }
    }
    f(0, -1, 0, 0);
}
