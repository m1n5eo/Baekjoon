#include <iostream> // BOJ 29704
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 1111

int n, t, sum;
vector<int> day(1, 0), money(1, 0);
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int solve() {
    for(int i = 1; i <= n; i++) {
        for(int d = 1; d <= t; d++) {
            if(d-day[i] >= 0) dp[i][d] = max(dp[i-1][d], dp[i-1][d-day[i]] + money[i]);
            else dp[i][d] = dp[i-1][d];
        }
    }
    return sum-dp[n][t];
}

int main() {
    FASTIO

    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        day.push_back(temp1);
        money.push_back(temp2);
        sum += money.back();
    }

    cout << solve();
}#include <iostream> // BOJ 29704
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 1111

int n, t, sum;
vector<int> day(1, 0), money(1, 0);
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int solve() {
    for(int i = 1; i <= n; i++) {
        for(int d = 1; d <= t; d++) {
            if(d-day[i] >= 0) dp[i][d] = max(dp[i-1][d], dp[i-1][d-day[i]] + money[i]);
            else dp[i][d] = dp[i-1][d];
        }
    }
    return sum-dp[n][t];
}

int main() {
    FASTIO

    cin >> n >> t;
    for(int i = 1; i <= n; i++) {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        day.push_back(temp1);
        money.push_back(temp2);
        sum += money.back();
    }

    cout << solve();
}