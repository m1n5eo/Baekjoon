#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 128

int cnt = 0;
vector<vector<int>> tile(MAX, vector<int>(MAX, 0));

bool check(int k, int x, int y) {
    for(int i = x; i < x+k; i++) {
        for(int j = y; j < y+k; j++) {
            if(tile[i][j] != 0) return false;
        }
    }
    return true;
}

void recursion(int k, int x, int y) {
    cnt += 1;
    if(check(k/2, x, y) == true) tile[x+k/2-1][y+k/2-1] = cnt;
    if(check(k/2, x, y+k/2) == true) tile[x+k/2-1][y+k/2] = cnt;
    if(check(k/2, x+k/2, y) == true) tile[x+k/2][y+k/2-1] = cnt;
    if(check(k/2, x+k/2, y+k/2) == true) tile[x+k/2][y+k/2] = cnt;
    if(k == 2) return;

    recursion(k/2, x, y);
    recursion(k/2, x, y+k/2);
    recursion(k/2, x+k/2, y);
    recursion(k/2, x+k/2, y+k/2);
}

void solve() {
    int k, n, m;
    cin >> k >> m >> n;
    n -= 1; m -= 1;
    tile[n][m] = -1;
    
    recursion((1<<k), 0, 0);
    
    for(int i = (1<<k)-1; i >= 0; i--) {
        for(int j = 0; j < (1<<k); j++) {
            cout << tile[i][j] << " ";
        }
        cout << "\n";
    }
}

int main() {
    FASTIO
    solve();
}