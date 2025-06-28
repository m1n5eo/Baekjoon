#include <iostream> // BOJ 1949
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int n, temp, a, b;
vector<int> population(1, 0);
vector<vector<int>> graph(MAX, vector<int>(0)), dp(MAX, vector<int>(2, 0));
vector<bool> visit(MAX, false);

void dfs(int node) {
	visit[node] = true;

	for(int g : graph[node]) {
		if(visit[g] == false) {
			dfs(g);
			
			dp[node][0] += max(dp[g][0], dp[g][1]);
			dp[node][1] += dp[g][0];
		}
	}
}

int main() {
	FASTIO

	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> temp;
		population.push_back(temp);
		dp[i][1] = temp;
	}

	for(int _ = 0; _ < n-1; _++) {
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	dfs(1);

	cout << max(dp[1][0], dp[1][1]);
}