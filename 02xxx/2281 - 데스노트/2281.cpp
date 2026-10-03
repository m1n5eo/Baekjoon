#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2147483647
#define MAX 1111

int n, m;
vector<int> name(MAX);
vector<vector<int>> dp(MAX, vector<int>(MAX, INF));

int func(int index, int length) {
    if(index == n) return 0;
    else if(dp[index][length] != INF) return dp[index][length];

    dp[index][length] = (m-length+1)*(m-length+1) + func(index+1, name[index]+1);
    if(length + name[index] <= m) dp[index][length] = min(dp[index][length], func(index+1, length + name[index]+1));

    return dp[index][length];
}

int solve() {
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> name[i];
    return func(0, 0);
}

int main() {
    FASTIO
    cout << solve();
}