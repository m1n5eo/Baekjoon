#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<string> chess;
string temp;
pair<int, int> character = {7, 0};
queue<pair<int, int>> bfs, wall;

int dx[9] = {-1, 0, 1, -1, 1, -1, 0, 1, 0};
int dy[9] = {-1, -1, -1, 0, 0, 1, 1, 1, 0};

int solve() {
	for(int i = 7; i >= 0; i--) {
		for(int j = 0; j < 8; j++) {
			if(chess[i][j] == '#') {
				wall.push({i, j});
			}
		}
	}

	bfs.push({7, 0});

	while(bfs.size()) {
		int bfs_size = bfs.size();

		for(int _ = 0; _ < bfs_size; _++) {
			pair<int, int> now = bfs.front();
			bfs.pop();

			if(chess[now.first][now.second] == '#') {
				continue;
			}

			for(int k = 0; k < 9; k++) {
				pair<int, int> next = {now.first + dx[k], now.second + dy[k]};

				if(0 <= next.first && next.first < 8 && 0 <= next.second && next.second < 8) {
					if(next.first == 0 && next.second == 7) {
						return 1;
					}
					else if(chess[next.first][next.second] == '.') {
						bfs.push({next.first, next.second});
					}
				}
			}
		}

		int wall_size = wall.size();

		for(int _ = 0; _ < wall_size; _++) {
			pair<int, int> now = wall.front();
			pair<int, int> next = {now.first+1, now.second};
			wall.pop();

			chess[now.first][now.second] = '.';
			if(next.first < 8) {
				chess[next.first][next.second] = '#';
				wall.push(next);
			}
		}
	}

	return 0;
}

int main() {
	FASTIO

	for(int i = 0; i < 8; i++) {
		cin >> temp;
		chess.push_back(temp);
	}

	cout << solve();
}