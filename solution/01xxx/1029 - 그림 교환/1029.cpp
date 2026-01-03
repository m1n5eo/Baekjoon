#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n;
    cin >> n;
    vector<vector<int>> buy(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for(int j = 0; j < n; j++) {
            buy[i][j] = (temp[j] - '0');
        }
    }

    vector<vector<vector<int>>> dp((1<<n), vector<vector<int>>(n, vector<int>(10, 0)));
    int ret = 1; dp[1][0][0] = 1;
    for(int visited = 0; visited < (1<<n); visited++) {
        for(int artist = 0; artist < n; artist++) {
            if((visited & (1<<artist)) == 0) continue;
            for(int price = 0; price < 10; price++) {
                if(dp[visited][artist][price] == 0) continue;
                for(int next = 0; next < n; next++) {
                    if(artist == next) continue;
                    else if(price > buy[artist][next]) continue;
                    else if((visited & (1<<next)) != 0) continue;
                    dp[visited|(1<<next)][next][buy[artist][next]] = dp[visited][artist][price]+1;
                    ret = max(ret, dp[visited|(1<<next)][next][buy[artist][next]]);
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