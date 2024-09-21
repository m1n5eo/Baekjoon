#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, dp[MAX] = {0, 0, 1, 0, 0, };

int main() {
    FASTIO

    cin >> n;
    
    for(int i = 5; i <= n; i++) {
        if(dp[i-4] == 1 || dp[i-3] == 1 || dp[i-1] == 1) dp[i] = 0;
        else dp[i] = 1;
    }

    if(dp[n] == 0) cout << "SK";
    else cout << "CY";
}