#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int t, n, k, temp;
vector<int> coin;

int solve() {
	vector<int> dp(MAX, 0);
	dp[0] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++)
			if(j-coin[i] >= 0)
				dp[j] += dp[j-coin[i]];
	return dp[k];
}

int main() {
	FASTIO

	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		coin = vector<int>(1, 0);
		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> temp;
			coin.push_back(temp);
		}
		cin >> k;
		cout << solve() << "\n";
	}
}