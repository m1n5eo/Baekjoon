#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 1234567890
#define MAX 11111

int main() {
	FASTIO

	int n, m, u, v, w, k, x, y, temp;
	vector<vector<pii>> graph(MAX, vector<pii>(0));
	vector<bool> check(MAX, false);

	cin >> n >> m;

	for(int i = 0; i < m; i++) {
		cin >> u >> v >> w;

		graph[u].push_back({v, w});
		graph[v].push_back({u, w});
	}

	cin >> k >> x;

	for(int i = 0; i < k; i++) {
		cin >> temp;

		graph[MAX-1].push_back({temp, 0});
		check[temp] = true;
	}

	cin >> k >> y;

	for(int i = 0; i < k; i++) {
		cin >> temp;

		graph[MAX-2].push_back({temp, 0});
		check[temp] = true;
	}

	vector<vector<int>> dist(MAX, vector<int>(2, INF));
	vector<queue<pii>> q(2);

	for(int index = 0; index < 2; index++) {
		q[index].push({MAX-index-1, 0});
		dist[MAX-index-1][index] = 0;

		while(q[index].size()) {
			pii now = q[index].front();
			int graph_size = graph[q[index].front().first].size();
			q[index].pop();

			for(int i = 0; i < graph_size; i++) {
				pii next = graph[now.first][i];

				if(now.second + next.second < dist[next.first][index]) {
					dist[next.first][index] = now.second + next.second;
					q[index].push({next.first, now.second + next.second});
				}
			}
		}
	}

	int result = INF;

	for(int i = 1; i <= n; i++) {
		if(check[i] == true) continue;
		else if(dist[i][0] > x || dist[i][1] > y) continue;

		result = min(result, dist[i][0] + dist[i][1]);
	}

	if(result != INF) cout << result;
	else cout << -1;
}