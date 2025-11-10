#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, k, ret = 0;
    cin >> n >> k;
    for(int i = 2; i <= n; i++) ret = (ret+k)%i;
    return ret+1;
}

int main() {
    FASTIO
    cout << solve();
}