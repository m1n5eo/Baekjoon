#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1500

struct type {
	int a, b, c;
};

type init;
vector<vector<bool>> visit(MAX, vector<bool>(MAX, false));

int solve() {
	int total = init.a + init.b + init.c;
	if(total%3 != 0) return 0;

	queue<pair<int, int>> bfs;
	bfs.push({init.a, init.b});
	visit[init.a][init.b] = true;
	
	while(bfs.size()) {
		pair<int, int> now = bfs.front();
		bfs.pop();
		int third = total - now.first - now.second;

		if(now.first == now.second && now.second == third) return 1;
		else {
			if(now.first < now.second && visit[now.first+now.first][now.second-now.first] == false) {
				bfs.push({now.first+now.first, now.second-now.first});
				visit[now.first+now.first][now.second-now.first] = true;
			}
			else if(now.first > now.second && visit[now.first-now.second][now.second+now.second] == false) {
				bfs.push({now.first-now.second, now.second+now.second});
				visit[now.first-now.second][now.second+now.second] = true;
			}

			if(now.second < third && visit[now.first][now.second+now.second] == false) {
				bfs.push({now.first, now.second+now.second});
				visit[now.first][now.second+now.second] = true;
			}
			else if(now.second > third && visit[now.first][now.second-third] == false) {
				bfs.push({now.first, now.second-third});
				visit[now.first][now.second-third] = true;
			}

			if(now.first < third && visit[now.first+now.first][now.second] == false) {
				bfs.push({now.first+now.first, now.second});
				visit[now.first+now.first][now.second] = true;
			}
			else if(now.first > third && visit[now.first-third][now.second] == false) {
				bfs.push({now.first-third, now.second});
				visit[now.first-third][now.second] = true;
			}
		}
	}

	return 0;
}

int main() {
	FASTIO

	cin >> init.a >> init.b >> init.c;
	cout << solve();
}