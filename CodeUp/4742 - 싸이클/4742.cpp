#include <bits/stdc++.h>
using namespace std;

int memo[100];

int main() {
    int n, m, k;
    scanf("%d %d", &n, &m);
    k = (n*n)%m;
    while(1) {
        if(memo[k] == 1) break;
        memo[k] = 1;
        k = (k*n)%m;
    }
    int cnt = 0;
    for(int i = 0; i <= 97; i++) {
        if(memo[i] == 1) cnt++;
    }
    printf("%d", cnt);
}