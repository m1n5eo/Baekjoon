#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n;
pair<int, int> dp[1111111]; // 최소카운트, 전숫자

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    if(n == 1) {
        cout << "0\n1";
        return 0;
    }

    for(int i = 2; i <= n; i++) {
        dp[i].first = dp[i-1].first+1;
        dp[i].second = i-1;

        if(i%2 == 0) {
            if((dp[i].first != 0 && dp[i/2].first+1 < dp[i].first) || dp[i].first == 0) {
                dp[i].first = dp[i/2].first+1;
                dp[i].second = i/2;
            }
        }
        
        if(i%3 == 0) {
            if((dp[i].first != 0 && dp[i/3].first+1 < dp[i].first) || dp[i].first == 0) {
                dp[i].first = dp[i/3].first+1;
                dp[i].second = i/3;
            }
        }
    }

    cout << dp[n].first << "\n" << n << " ";
    for(int i = n; dp[i].second != 1; i=dp[i].second) {
        cout << dp[i].second << " ";
    }
    cout << "1";

    return 0;
}