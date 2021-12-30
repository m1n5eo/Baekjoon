#include <bits/stdc++.h>
using namespace std;

int n, bu[11], chk[11]; /// bu1."+"   bu2."-"   bu3." "

int bu3ch(int idxx, int summ) {
    if(bu[idxx-1] == 1) {
        summ = summ-(idxx-1);
        summ = summ+((idxx-1)*10+idxx);

    }
    else if(bu[idxx-1] == 2) {
        summ = summ+(idxx-1);
        summ = summ-((idxx-1)*10+idxx);
    }
    return summ;
}

void f(int idx, int sum) {
    if(idx > n && sum == 0) {
        int cnt = 0;
        for(int i = 1; i <= n; i++) {
            if(chk[i] == bu[i]) cnt++;
        }
        if(cnt == n) return;

        printf("1"); /// 출력
        for(int i = 2; i <= n; i++) {
            if(bu[i] == 1) printf("+");
            else if(bu[i] == 2) printf("-");
            else if(bu[i] == 3) printf(" ");
            printf("%d", i);
        }
        printf("\n"); /// 출력 끝

        for(int i = 1; i <= n; i++) chk[i] = bu[i];
    }
    else if(idx > n) return;

    bu[idx] = 3;
    if(bu[idx-1] != 3) f(idx+1, bu3ch(idx, sum));
    bu[idx] = 1;
    f(idx+1, sum+idx);
    bu[idx] = 2;
    f(idx+1, sum-idx);
}

int main() {
    scanf("%d", &n);
    bu[1] = 1;
    f(2, 1);
    //printf("%d", b);
}