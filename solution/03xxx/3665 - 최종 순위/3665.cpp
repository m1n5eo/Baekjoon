#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555

int t, n, m, temp, a, b;
vector<int> last, cnt, ranking, result;
vector<vector<int>> graph;
vector<vector<bool>> check;
queue<int> q;

bool solve() {
	for(int i = 1; i <= n; i++) {
		for(int j = i+1; j <= n; j++) {
			int x = last[i], y = last[j];
			if(check[x][y] == true) return false;
			else if(check[y][x] == false) {
				graph[x].push_back(y);
				cnt[y] += 1;
			}
		}
	}

	for(int i = 1; i <= n; i++) if(cnt[i] == 0) {
		q.push(i);
		result.push_back(i);
	}

	while(!q.empty()) {
		int now = q.front();
		int graph_size = graph[now].size();
		q.pop();
		for(int i = 0; i < graph_size; i++) {
			int next = graph[now][i];
			if(cnt[next] == 0) continue;
			else if(cnt[next]-1 == 0) {
				cnt[next] -= 1;
				q.push(next);
				result.push_back(next);
			}
			else cnt[next] -= 1;
		}
	}
	
	return result.size() == n? true : false;
}

int main() {
	FASTIO

	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		last = vector<int>(MAX, 0), cnt = vector<int>(MAX, 0), ranking = vector<int>(MAX, 0);
		graph = vector<vector<int>>(MAX, vector<int>(0));
		check = vector<vector<bool>>(MAX, vector<bool>(MAX, false));
		result.clear();
		while(!q.empty()) q.pop();

		cin >> n;
		for(int i = 1; i <= n; i++) {
			cin >> last[i];
			ranking[last[i]] = i;
		}
		cin >> m;
		for(int i = 0; i < m; i++) {
			cin >> a >> b;
			if(ranking[a] < ranking[b]) swap(a, b);
			graph[a].push_back(b);
			cnt[b] += 1;
			check[a][b] = true;
		}

		bool sol = solve();
		if(sol) for(int r: result) cout << r << " ";
		else cout << "IMPOSSIBLE";
		cout << "\n";
	}
}