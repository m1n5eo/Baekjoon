#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 2222

int testcase;

int main() {
	FASTIO

	cin >> testcase;
	for(int tc = 1; tc <= testcase; tc++) {
		int n, m, t, s, g, h, a, b, d, temp;
		vector<int> go;
		vector<vector<int>> dist(MAX, vector<int>(MAX, INF)), cost(3, vector<int>(MAX, INF));
		vector<vector<bool>> visit(3, vector<bool>(MAX, false));

		cin >> n >> m >> t;
		cin >> s >> g >> h;
		for(int i = 0; i < m; i++) {
			cin >> a >> b >> d;
			dist[a][b] = d;
			dist[b][a] = d;
		}
		for(int i = 0; i < t; i++) {
			cin >> temp;
			go.push_back(temp);
		}

		for(int i = 1; i <= n; i++) {
			dist[i][i] = 0;
			cost[0][i] = dist[g][i];
			cost[1][i] = dist[h][i];
			cost[2][i] = dist[s][i];
		}

		visit[0][g] = true;
		visit[1][h] = true;
		visit[2][s] = true;

		for(int k = 0; k < 3; k++) {
			for(int _ = 0; _ < n; _++) {
				int small = INF, idx = 0;
				for(int i = 1; i <= n; i++) if(!visit[k][i] && cost[k][i] <= small) {
					small = cost[k][i];
					idx = i;
				}
				if(idx == 0) break;
				visit[k][idx] = true;
				for(int i = 1; i <= n; i++) if(!visit[k][i] && cost[k][idx] + dist[idx][i] < cost[k][i]) cost[k][i] = cost[k][idx] + dist[idx][i];
			}
		}

		sort(go.begin(), go.end());
		for(int x: go) if(cost[2][x] == min(cost[0][s] + cost[0][h] + cost[1][x], cost[1][s] + cost[0][h] + cost[0][x])) cout << x << " ";
		cout << "\n";
	}
}