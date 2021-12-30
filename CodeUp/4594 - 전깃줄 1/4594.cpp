#include <bits/stdc++.h>
using namespace std;

int LIS[501];

int main() {
    int n;
    scanf("%d", &n);
    pair <int, int> p[501];
    for(int i = 0; i < n; i++) {
        scanf("%d %d", &p[i].first, &p[i].second);
    }
    sort(p, p+n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(p[i].second > p[j].second && LIS[j] + 1 > LIS[i]) {
                LIS[i] = LIS[j] + 1;
            }
        }
    }
    //for(int i = 0; i < n; i++) printf("%d\n", LIS[i]);
    sort(LIS, LIS+n);
    printf("%d", n-LIS[n-1]-1);

}