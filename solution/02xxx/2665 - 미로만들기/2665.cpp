#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 51

struct type {
	int x, y, cnt;
};

int n;
string temp;
vector<vector<int>> board(MAX, vector<int>(MAX, 0));
vector<vector<int>> visit(MAX, vector<int>(MAX, INF));

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

struct compare {
	bool operator()(type a, type b) {
		return a.cnt > b.cnt;
	}
};

int solve() {
	priority_queue<type, vector<type>, compare> pq;
	pq.push({0, 0, 0});
	visit[0][0] = 0;

	while(!pq.empty()) {
		type now = pq.top();
		pq.pop();
		for(int k = 0; k < 4; k++) {
			if(0 <= now.x + dx[k] && now.x + dx[k] < n && 0 <= now.y + dy[k] && now.y + dy[k] < n) {
				type next = {now.x + dx[k], now.y + dy[k], now.cnt + (board[now.x + dx[k]][now.y + dy[k]] == 0? 1 : 0)};
				if(next.x == n-1 && next.y == n-1) return next.cnt;
				else if(visit[next.x][next.y] > next.cnt) {
					pq.push(next);
					visit[next.x][next.y] = next.cnt;
				}
			}
		}
	}

	return 0;
}

int main() {
	FASTIO
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		for(int j = 0; j < n; j++) {
			if(temp[j] == '1') board[i][j] = -1;
			else if(temp[j] == '0') board[i][j] = 0;
		}
	}

	cout << solve();
}