#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, minn = 1234567890, maxx = -1234567890;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &k);
        minn = min(k, minn);
        maxx = max(k, maxx);
    }
    printf("%d %d", minn, maxx);
}
