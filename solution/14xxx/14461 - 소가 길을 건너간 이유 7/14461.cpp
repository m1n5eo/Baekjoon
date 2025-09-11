#include <iostream> // BOJ 14461
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 111

struct type {
	int x, y, cnt, total;
};

struct compare {
	bool operator()(type a, type b) {
		return a.total > b.total;
	}
};

int n, m;
vector<vector<int>> grass(MAX, vector<int>(MAX, 0));
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int solve() {
	int ret = INF;
	vector<vector<vector<bool>>> visit(MAX, vector<vector<bool>>(MAX, vector<bool>(4, false)));
	priority_queue<type, vector<type>, compare> bfs;
	bfs.push({0, 0, 0, 0});
	visit[0][0][0] = true;
	while(!bfs.empty()) {
		type now = bfs.top();
		bfs.pop();
		for(int k = 0; k < 4; k++) {
			type next = {now.x+dx[k], now.y+dy[k], now.cnt+1, now.total};
			if(0 <= next.x && next.x < n && 0 <= next.y && next.y < n) {
				if(visit[next.x][next.y][next.cnt] == false) {
					if(next.cnt == 3) {
						next.cnt = 0;
						next.total += m+grass[next.x][next.y];
						if(next.x == n-1 && next.y == n-1) ret = min(ret, next.total);
						bfs.push(next);
						visit[next.x][next.y][next.cnt] = true;
					}
					else if(next.cnt < 3) {
						next.total += m;
						if(next.x == n-1 && next.y == n-1) ret = min(ret, next.total);
						bfs.push(next);
						visit[next.x][next.y][next.cnt] = true;
					}
				}
			}
		}
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> grass[i][j];
	cout << solve();
}