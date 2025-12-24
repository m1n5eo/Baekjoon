#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

char solve() {
    int n; cin >> n;
    return n != 1? 'A' : 'B';
}

int main() {
    FASTIO
    cout << solve();
}