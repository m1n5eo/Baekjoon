#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 22222

int t, n, m, u, v;
vector<vector<int>> graph;
vector<int> color;

string search(int index) {
	queue<int> bfs;
	bfs.push(index);
	color[index] = 0;

	while(!bfs.empty()) {
		int now = bfs.front();
		int graph_size = graph[now].size();
		bfs.pop();

		for(int i = 0; i < graph_size; i++) {
			if(color[graph[now][i]] == -1) {
				bfs.push(graph[now][i]);
				color[graph[now][i]] = 1-color[now];
			}
			else if(color[graph[now][i]] + color[now] != 1) return "NO";
		}
	}
	return "YES";
}

string solve() {
	string ret;
	for(int i = 1; i <= n; i++) if(color[i] == -1 && search(i) == "NO") return "NO";
	return "YES";
}

int main() {
	FASTIO

	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		graph = vector<vector<int>>(MAX, vector<int>(0));
		color = vector<int>(MAX, -1);

		cin >> n >> m;
		for(int _ = 0; _ < m; _++) {
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		cout << solve() << "\n";
	}
}