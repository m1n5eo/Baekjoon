#include <iostream>
using namespace std;

#define MOD 1000000007
#define MAX 1000001

int n, dp[MAX] = {0, 1, };

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int i = 2; i < MAX; i++) {
        dp[i] = (dp[i-1]+dp[i-2])%MOD;
    }

    cin >> n;
    cout << dp[n]%MOD;
}