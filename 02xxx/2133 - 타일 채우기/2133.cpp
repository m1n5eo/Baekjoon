#include <iostream>
using namespace std;

int main() {
    int n, dp[33] = {0, 0, 3, 0, 11, 0, };
    cin >> n;
    for(int i = 6; i <= 30; i++) {
        if(i%2 == 1) dp[i] = 0;
        else {
            dp[i] = dp[i-2]*4 - dp[i-4];
        }
    }
    cout << dp[n];
}