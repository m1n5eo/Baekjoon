#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
	int n, k, x, y, w;
	cin >> n >> k;
	vector<int> delay(n+1, 0), cnt(n+1, 0), dp(n+1, 0);
	vector<vector<int>> graph(n+1, vector<int>(0));
	queue<int> que;
	for(int i = 1; i <= n; i++) cin >> delay[i];
	for(int _ = 0; _ < k; _++) {
		cin >> x >> y;
		cnt[y] += 1;
		graph[x].push_back(y);
	}
	cin >> w;
	for(int i = 1; i <= n; i++) {
		if(cnt[i] == 0) {
			que.push(i);
			dp[i] = delay[i];
		}
	}
	while(!que.empty()) {
		int now = que.front();
		que.pop();
		for(int next : graph[now]) {
			if(cnt[next] == 0) continue;
			else if(cnt[next]-1 == 0) que.push(next);
			cnt[next] -= 1;
			dp[next] = max(dp[next], dp[now] + delay[next]);
		}
	}
	return dp[w];
}

int main() {
	FASTIO
	int tc; cin >> tc;
	while(tc--) cout << solve() << "\n";
}