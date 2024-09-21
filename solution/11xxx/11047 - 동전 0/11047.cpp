#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, cnt = 0, coin[11];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++) scanf("%d", &coin[i]);

    for(int i = n-1; i >= 0; i--) {
        if(coin[i] <= k) {
            cnt = cnt + (k/coin[i]);
            k = k-((k/coin[i])*coin[i]);
        }
    }

    printf("%d", cnt);
}
