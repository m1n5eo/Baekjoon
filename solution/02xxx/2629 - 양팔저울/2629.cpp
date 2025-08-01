#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX_N 33
#define MAX_M 44444

int n, m, question, temp;
vector<int> weight;
vector<vector<bool>> dp(MAX_N, vector<bool>(MAX_M, false));

void solve(int idx, int now) {
	if(idx > n || dp[idx][now]) return;
	dp[idx][now] = true;
	solve(idx+1, now);
	solve(idx+1, now+weight[idx]);
	solve(idx+1, abs(now-weight[idx]));
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		weight.push_back(temp);
	}
	solve(0, 0);
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> question;
		cout << (dp[n][question]? "Y ":"N ");
	}
}