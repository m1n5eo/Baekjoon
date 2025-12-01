#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli solve() {
    lli n, m;
    cin >> n >> m;
    vector<vector<lli>> init(n, vector<lli>(n, 0)), imos(n+1, vector<lli>(n+1, 0));
    for(lli i = 0; i < n; i++) {
        for(lli j = 0; j < n; j++) {
            cin >> init[i][j];
        }
    }
    for(lli _ = 0; _ < m-1; _++) {
        lli mode, x1, y1, x2, y2, k; cin >> mode >> x1 >> y1 >> x2 >> y2 >> k;
        imos[x1][y1] += k;
        imos[x1][y2+1] -= k;
        imos[x2+1][y1] -= k;
        imos[x2+1][y2+1] += k;
    }

    for(lli i = 0; i < n; i++) {
        for(lli j = 0; j < n; j++) {
            if(j != 0) {
                imos[i][j] += imos[i][j-1];
            }
        }
    }
    for(lli i = 0; i < n; i++) {
        for(lli j = 0; j < n; j++) {
            if(i != 0) {
                imos[i][j] += imos[i-1][j];
            }
        }
    }
    
    lli mode, x1, y1, x2, y2, ret = 0;
    cin >> mode >> x1 >> y1 >> x2 >> y2;
    for(lli i = x1; i <= x2; i++) {
        for(lli j = y1; j <= y2; j++) {
            ret += init[i][j] + imos[i][j];
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}