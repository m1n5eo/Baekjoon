#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, rope[111111], max_rope = 0;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> rope[i];
    }

    sort(rope, rope+n);

    for(int i = 1; i <= n; i++) {
        max_rope = max(max_rope, rope[n-i]*i);
    }

    cout << max_rope;

    return 0;
}