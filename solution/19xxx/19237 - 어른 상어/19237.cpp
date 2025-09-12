#include <iostream> // BOJ 19237
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 22

struct type {
	int x = -1, y = -1, direction = -1, index = -1, turn = -1;
};

struct compare {
	bool operator()(type a, type b) {
		if(a.turn != b.turn) return a.turn > b.turn;
		else return a.index < b.index;
	}
};

int n, m, k, temp;
vector<pair<int, int>> coordinate(MAX*MAX, {-1, -1}); // 처음 시작 좌표를 입력받기 위한 vector. 입력만 받고 이후엔 사용되지 않음.
vector<vector<int>> board(MAX, vector<int>(MAX, 0)); // shark의 냄새가 있는 곳을 index로 표시
vector<vector<int>> cnt(MAX, vector<int>(MAX, 0));
vector<vector<vector<int>>> priority(MAX*MAX, vector<vector<int>>(5, vector<int>(5, -1))); // shark의 number, direction에 따른 이동 우선순위
queue<pair<pair<int, int>, int>> smell; // 시간 지나면 냄새 없애기 위한 vector. element : coordinate, cnt(몇번째 turn에서 생긴 smell인지 나타냄.)
priority_queue<type, vector<type>, compare> shark; // shark에 대한 information 저장. element : coordinate, direction, index, cnt
vector<int> dx = {100, -1, 1, 0, 0};
vector<int> dy = {100, 0, 0, -1, 1};

void print(int idx) {
	if(idx == 0) {
		cout << "\n" << "board" << " " << shark.top().turn << "\n";
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				cout << board[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
}

int solve() {
	int ret = 0;
	while(shark.size() > 1 && ret < 1001) {
		vector<bool> check(MAX*MAX, false);
		vector<type> nc(MAX*MAX), temp_next, imsi;
		int shark_size = shark.size();
		ret += 1;
		// print(0);
		for(int _ = 0; _ < shark_size; _++) {
			type now = shark.top();
			shark.pop();
			// cout << now.x << " " << now.y << " " << now.direction << " " << now.index << " " << now.turn << "\n";
			for(int i = 1; i <= 4; i++) {
				int t = priority[now.index][now.direction][i];
				int nx = now.x+dx[t], ny = now.y+dy[t];
				if(1 <= nx && nx <= n && 1 <= ny && ny <= n) {
					if(board[nx][ny] == 0) {
						nc[now.index] = {nx, ny, t, now.index, ret};
						break;
					}
				}
			}
			if(nc[now.index].x == -1) {
				for(int i = 1; i <= 4; i++) {
					int t = priority[now.index][now.direction][i];
					int nx = now.x+dx[t], ny = now.y+dy[t];
					if(1 <= nx && nx <= n && 1 <= ny && ny <= n) {
						if(board[nx][ny] == now.index) {
							nc[now.index] = {nx, ny, t, now.index, ret};
							break;
						}
					}
				}
			}
			temp_next.push_back(nc[now.index]);
		}
		while(!smell.empty() && ret - smell.front().second >= k) {
			pair<int, int> rm = smell.front().first;
			if(cnt[rm.first][rm.second] < 2) board[rm.first][rm.second] = 0;
			smell.pop();
			cnt[rm.first][rm.second] -= 1;
		}
		for(type next : temp_next) {
			if(board[next.x][next.y] == 0 || board[next.x][next.y] == next.index) {
				board[next.x][next.y] = next.index;
				cnt[next.x][next.y] += 1;
				smell.push({{next.x, next.y}, next.turn});
				check[next.index] = true;
				imsi.push_back(next);
			}
			else if(board[next.x][next.y] > next.index) {
				check[board[next.x][next.y]] = false;
				board[next.x][next.y] = next.index;
				cnt[next.x][next.y] += 1;
				smell.push({{next.x, next.y}, next.turn});
				check[next.index] = true;
				imsi.push_back(next);
			}
		}
		for(type i : imsi) if(check[i.index] == true) shark.push(i);
	}
	return ret < 1001? ret : -1;
}

int main() {
	FASTIO

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cin >> temp;
			if(temp != 0) {
				coordinate[temp] = {i, j};
				board[i][j] = temp;
				cnt[i][j] += 1;
				smell.push({{i, j}, 0});
			}
		}
	}
	for(int i = 1; i <= m; i++) {
		cin >> temp;
		shark.push({coordinate[i].first, coordinate[i].second, temp, i, 0});
	}
	for(int t = 1; t <= m; t++) {
		for(int i = 1; i <= 4; i++) {
			for(int j = 1; j <= 4; j++) {
				cin >> temp;
				priority[t][i][j] = temp;
			}
		}
	}
	cout << solve();
}