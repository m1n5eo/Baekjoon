#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000000
#define MAX 1111111

lli n, dp[MAX] = {0, 0, 1, };

int main() {
    FASTIO

    cin >> n;
    
    for(int i = 3; i <= n; i++) {
        dp[i] = ((dp[i-1]+dp[i-2])*(i-1))%MOD;
    }

    cout << dp[n];
}