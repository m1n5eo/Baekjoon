#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second

int LIS[501];

int main() {
    int n;
    scanf("%d", &n);
    pair<int, int> p[501];
    for(int i = 0; i < n; i++) scanf("%d %d", &p[i].fi, &p[i].se);
    sort(p, p+n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(p[i].se > p[j].se && LIS[j]+1 > LIS[i]) {
                LIS[i] = LIS[j]+1;
            }
        }
    }
    sort(LIS, LIS+n);
    printf("%d", n-LIS[n-1]-1);
}