#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int main() {
    FASTIO

    int n;
    vector<lli> dp(33, 1);

    cin >> n;

    for(int i = 4; i <= n; i+=2) {
        dp[i] = dp[i-2]*(i-1);
    }

    cout << dp[n];
}