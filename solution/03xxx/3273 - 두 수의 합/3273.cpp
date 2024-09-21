#include <iostream>
#include <algorithm>
using namespace std;

#define num 2222222

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, x, temp;
    int cnt[num] = {0, };

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        cnt[temp] += 1;
    }
    cin >> x;

    int res = 0;

    if(x%2 == 0) {
        for(int i = 1; i < x/2; i++) {
            res += min(cnt[i], cnt[x-i]);
        }
        for(int i = 1; i < cnt[x/2]; i++) {
            res += i;
        }
    }
    else if(x%2 == 1) {
        for(int i = 1; i <= x/2; i++) {
            res += min(cnt[i], cnt[x-i]);
        }
    }

    cout << res;

    return 0;
}