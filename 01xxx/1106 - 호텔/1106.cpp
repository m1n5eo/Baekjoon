#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 2222

struct type {
	int cost, people;
};

int n, k;
type temp;
vector<type> vec(1, {0, 0});

int solve() {
	int ret = INF;
	vector<vector<int>> dp(n+1, vector<int>(MAX, INF));
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j < MAX; j++) {
			if(j >= vec[i].people) dp[i][j] = min(dp[i-1][j], (dp[i][j-vec[i].people] == INF? 0 : dp[i][j-vec[i].people]) + vec[i].cost);
			else if(j <= vec[i].people) dp[i][j] = min(dp[i-1][j], vec[i].cost);
		}
	}
	for(int j = k; j < MAX; j++) ret = min(ret, dp[n][j]);
	return ret;
}

int main() {
	FASTIO

	cin >> k >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp.cost >> temp.people;
		vec.push_back(temp);
	}
	cout << solve();
}