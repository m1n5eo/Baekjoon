#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000007

vector<vector<lli>> cal(vector<vector<lli>> a, vector<vector<lli>> b) {
    vector<vector<lli>> rtn = {{0, 0}, {0, 0}};
    for(lli i = 0; i < 2; i++) {
        for(lli j = 0; j < 2; j++) {
            for(lli k = 0; k < 2; k++) {
                rtn[i][j] = (rtn[i][j] + a[i][k]*b[k][j]) % MOD;
            }
        }
    }
    return rtn;
}

vector<vector<lli>> expo(vector<vector<lli>> matrix, lli p) {
    if(p <= 1) {
        vector<vector<lli>> a = {{1, 1}, {1, 0}};
        vector<vector<lli>> b = {{1, 1}, {1, 1}};
        return p == 1? a : b;
    }
    else {
        vector<vector<lli>> e = expo(matrix, p/2);
        return p%2 == 0? cal(e, e) : cal(cal(e, e), {{1, 1}, {1, 0}});
    }
}

int solve() {
    lli n; cin >> n;
    vector<vector<lli>> matrix = expo({{1, 1}, {1, 0}}, n);
    return matrix[0][0]*matrix[0][1] % MOD;
}

int main() {
    FASTIO
    cout << solve();
}