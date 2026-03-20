#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solution() {
    int n;
    cin >> n;
    vector<int> array(n), dp(n);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
        if(i == 0) dp[i] = array[i];
        else dp[i] = max(array[i], dp[i-1] + array[i]);
    }
    sort(dp.begin(), dp.end());
    return dp[n-1];
}

int main() {
    FASTIO
    cout << solution();
}