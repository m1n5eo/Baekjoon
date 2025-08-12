#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int t, n, temp;
vector<int> card;

int solve() {
	vector<vector<int>> dp(MAX, vector<int>(MAX, 0));
	for(int k = 0; k < n; k++) {
		for(int i = 0; i < n-k; i++) {
			if(k == 0 && n%2 == 1) dp[i][i] = card[i];
			else if(n%2 + k%2 == 1) dp[i][i+k] = max(dp[i+1][i+k] + card[i], dp[i][i+k-1] + card[i+k]);
			else dp[i][i+k] = min(dp[i+1][i+k], dp[i][i+k-1]);
		}
	}
	return dp[0][n-1];
}

int main() {
	FASTIO
	
	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n;
		for(int i = 0; i < n; i++) {
			cin >> temp;
			card.push_back(temp);
		}
		cout << solve() << "\n";
		card.clear();
	}
}