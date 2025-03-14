#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define endl "\n"
#define MAX 1111

int main() {
	FASTIO
	
	int testcase;
	vector<string> result;

	cin >> testcase;

	for(int tc = 0; tc < testcase; tc++) {
		int n, m, x, y, start;
		vector<vector<int>> graph(MAX, vector<int>(0));
		vector<int> color(MAX, 0);

		cin >> n >> m;

		for(int _ = 0; _ < m; _++) {
			cin >> x >> y;

			graph[x].push_back(y);
			graph[y].push_back(x);
		}

		for(int i = 1; i <= n; i++) {
			if(color[i] == 0) {
				queue<int> bfs;
				bfs.push(i);
				color[i] = 1;

				while(bfs.size()) {
					int now = bfs.front();
					bfs.pop();

					for(int g : graph[now]) {
						if(color[g] == 0) {
							color[g] = -color[now];
							bfs.push(g);
						}
						else if(color[g] == color[now]) {
							if(result.size() == tc) {
								result.push_back("impossible");
							}
						}
					}
				}
			}
		}

		if(result.size() == tc) {
			result.push_back("possible");
		}
	}

	for(string r : result) {
		cout << r << endl;
	}
}