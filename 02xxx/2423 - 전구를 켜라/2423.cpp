#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define MAX 555

struct type {
	int x, y, cnt, circuit;
};

int n, m;
string temp;
vector<vector<int>> board(MAX, vector<int>(MAX, INF));
vector<vector<int>> visit(MAX, vector<int>(MAX, INF));

vector<vector<int>> dx = {{-1, -1, 0, 1, 1, 0}, {-1, -1, 0, 1, 1, 0}};
vector<vector<int>> dy = {{-1, 0, 1, 1, 0, -1}, {0, 1, 1, 0, -1, -1}};
vector<vector<int>> dc = {{0, 1, 1, 0, 1, 1}, {0, 1, 0, 0, 1, 0}};

struct compare {
	bool operator()(type a, type b) {
		return a.cnt > b.cnt;
	}
};

string solve() {
	if(n%2 != m%2) return "NO SOLUTION";
	else if(n == 1 && m == 1) return to_string(board[0][0] == 0? 0 : 1);

	priority_queue<type, vector<type>, compare> pq;
	pq.push({0, 0, (board[0][0] == 0? 0 : 1), 0});
	visit[0][0] = (board[0][0] == 0? 0 : 1);

	while(!pq.empty()) {
		type now = pq.top();
		pq.pop();
		for(int k = 0; k < 6; k++) {
			type next = {now.x+dx[now.circuit][k], now.y+dy[now.circuit][k], now.cnt, now.circuit};
			if(0 <= next.x && next.x < n && 0 <= next.y && next.y < m) {
				next.cnt += (dc[now.circuit][k] != board[next.x][next.y]? 1 : 0);
				next.circuit = dc[now.circuit][k];
				if(next.x == n-1 && next.y == m-1) return to_string(next.cnt);
				else if(visit[next.x][next.y] > next.cnt) {
					pq.push(next);
					visit[next.x][next.y] = next.cnt;
				}
			}
		}
	}
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		for(int j = 0; j < m; j++) {
			if(temp[j] == '/') board[i][j] = 1;
			else board[i][j] = 0;
		}
	}

	cout << solve();
}