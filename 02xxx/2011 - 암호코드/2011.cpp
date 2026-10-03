#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MOD 1000000
#define MAX 5555

int main() {
    FASTIO

    string pw;
    vector<lli> password, dp(MAX, 0);

    dp[0] = 1;
    dp[1] = 1;

    cin >> pw;

    int n = pw.size();

    for(char pwd : pw) {
        password.push_back(pwd-'0');
    }

    if(n >= 2 && password[0]*10 + password[1] <= 26 && password[1] != 0) dp[1] = 2;
    else if(n >= 2 && password[0]*10 + password[1] <= 26 && password[1] == 0) dp[1] = 1;
    else if(n >= 2 && password[0]*10 + password[1] > 26 && password[1] == 0) dp[1] = 0;

    if(password[0] == 0) {
        cout << 0;
        exit(0);
    }

    for(int i = 2; i < n; i++) {
        if(password[i-1] == 0 && password[i] == 0) {
            break;
        }
        else if(password[i-1] != 0 && password[i] == 0) {
            if(password[i-1]*10 + password[i] <= 26) dp[i] = dp[i-2];
            else break;
        }
        else if(password[i-1] == 0 && password[i] != 0) {
            dp[i] = dp[i-1];
        }
        else if(password[i-1] != 0 && password[i] != 0) {
            if(password[i-1]*10 + password[i] <= 26) dp[i] = (dp[i-2]+dp[i-1]) % MOD;
            else dp[i] = dp[i-1];
        }
    }

    cout << dp[n-1];
}