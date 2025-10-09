#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> land(n+1, vector<int>(m+1, 0)), prefix(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cin >> land[i][j];
            prefix[i][j] = prefix[i][j-1] + prefix[i-1][j] - prefix[i-1][j-1] + land[i][j];
        }
    }

    // cout << "\n" << "prefix" << "\n";
    // for(int i = 1; i <= n; i++) {
    //     for(int j = 1; j <= m; j++) {
    //         cout << prefix[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    // cout << "\n";

    int ret = 0;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int x = i; x <= n; x++) {
                for(int y = j; y <= m; y++) {
                    int now = prefix[x][y] + prefix[i-1][j-1] - prefix[x][j-1] - prefix[i-1][y];
                    // cout << i << " " << j << " / " << x << " " << y << " / " << now << "\n";
                    if(now > 10) break;
                    else if(now == 10) {
                        ret += 1;
                        break;
                    }
                }
            }
        }
    }

    return ret;
}

int main() {
    FASTIO
    cout << solve();
}