#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int coin;
    cin >> coin;
    for(int i = coin/5; i >= 0; i--) if((coin-i*5)%2 == 0) return i + (coin-i*5)/2;
    return -1;
}

int main() {
    FASTIO
    cout << solve();
}