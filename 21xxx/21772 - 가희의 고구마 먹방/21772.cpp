#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, t;
pair<int, int> coordinate;
string temp;
vector<vector<int>> board;
queue<pair<int, int>> bfs;
vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

int solve(pair<int, int> now, int turn, int cnt) {
	if(turn > t) return cnt;
	// cout << now.first << " " << now.second << " | " << turn << " " << cnt << "\n";
 	int ret = 0;
	for(int k = 0; k < 4; k++) {
		int nx = now.first+dx[k], ny = now.second+dy[k];
		if(!(0 <= nx && nx < n && 0 <= ny && ny < m) || board[nx][ny] == 2) continue;
		else if(board[nx][ny] == 0) ret = max(ret, solve({nx, ny}, turn+1, cnt));
		else if(board[nx][ny] == 1) {
			board[nx][ny] = 0;
			if(turn+1 > t) ret = max(ret, solve({nx, ny}, turn+1, cnt));
			else ret = max(ret, solve({nx, ny}, turn+1, cnt+1));
			board[nx][ny] = 1;
		}
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n >> m >> t;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		board.push_back(vector<int>(0));
		for(int j = 0; j < m; j++) {
			if(temp[j] == '.') board[i].push_back(0);		// 빈 방
			else if(temp[j] == 'G') {						// 가희
				board[i].push_back(0);
				coordinate = {i, j};
			}
			else if(temp[j] == 'S') board[i].push_back(1);	// 고구마
			else if(temp[j] == '#') board[i].push_back(2);	// 벽
		}
	}
	cout << solve(coordinate, 0, 0);
}