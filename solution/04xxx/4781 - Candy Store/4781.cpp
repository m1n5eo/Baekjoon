#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve(int n, double m) {
    int money = round(m*100);
    double price;
    vector<pair<int, int>> candy(n+1, {0, 0});
    vector<int> dp(money+1, 0);
    for(int i = 1; i <= n; i++) {
        cin >> candy[i].first >> price;
        candy[i].second = round(price*100);
    }
    for(int i = 1; i <= n; i++) {
        for(int j = candy[i].second; j <= money; j++) {
            dp[j] = max(dp[j], dp[j-candy[i].second] + candy[i].first);
        }
    }
    return dp[money];
}

int main() {
    FASTIO
    while(true) {
        int n; double m;
        cin >> n >> m;
        if(n == 0 && m == 0) break;
        cout << solve(n, m) << "\n";
    }
}