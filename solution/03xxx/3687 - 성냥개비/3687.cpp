#include <iostream>
#include <utility>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 100000000000000000
#define MAX 111

int main() {
    FASTIO

    vector<int> match = {0, 0, 1, 7, 3, 2, 0, 8};
    vector<pair<lli, string>> dp(MAX, {INF, ""});

    dp[2] = {1, "1"};
    dp[3] = {7, "7"};
    dp[4] = {4, "11"};
    dp[5] = {2, "71"};
    dp[6] = {6, "111"};
    dp[7] = {8, "711"};
    dp[8] = {10, "1111"};

    for(int i = 9; i <= 100; i++) {        
        for(int k = 2; k <= 7; k++) {
            dp[i].first = min(dp[i].first, dp[i-k].first*10 + match[k]);
        }
        dp[i].second = dp[i-2].second + "1";
    }

    int tc;
    cin >> tc;

    for(int testcase = 0; testcase < tc; testcase++) {
        int n;

        cin >> n;
        cout << dp[n].first << " " << dp[n].second << "\n";
    }
}