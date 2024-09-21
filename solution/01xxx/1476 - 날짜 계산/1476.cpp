#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if(n == 15) n = 0;
    if(m == 28) m = 0;
    if(k == 19) k = 0;
    for(int i = 1; i <= 7980; i++) {
        if(i%15 == n && i%28 == m && i%19 == k) {
            printf("%d", i);
            break;
        }
    }
}
