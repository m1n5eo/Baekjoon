#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

void solve() {
    int n;
    cin >> n;
    if(n%4 != 0) {
        cout << -1;
        return;
    }

    vector<string> tile;
    tile.push_back("aaab");
    tile.push_back("dabb");
    tile.push_back("ddcb");
    tile.push_back("dccc");

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) cout << tile[i%4][j%4];
        cout << "\n";
    }
    return;
}

int main() {
    FASTIO
    solve();
}