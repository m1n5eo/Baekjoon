#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 22

bool compare(int x, int y) {
    return x < y;
}

int main() {
    FASTIO

    int n;

    cin >> n;

    vector<int> day(MAX, 0), money(MAX, 0), dp(MAX, 0);

    for(int i = 1; i <= n; i++) {
        cin >> day[i] >> money[i];

        if(day[i]+i > n+1) {
            day[i] = 0;
            money[i] = 0;
        }
    }

    dp[1] = money[1];

    for(int i = 2; i <= n; i++) {
        dp[i] = money[i];

        for(int j = 1; j < i; j++) {
            if(day[j]+j <= i) {
                dp[i] = max(dp[i], money[i]+dp[j]);
            }
        }
    }

    sort(dp.begin()+1, dp.begin()+n+1, compare);
    
    cout << dp[n];
}