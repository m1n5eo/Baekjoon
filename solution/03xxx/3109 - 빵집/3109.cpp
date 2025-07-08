#include <iostream> // BOJ 3109
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, result = 0;
bool check;
string temp;
vector<vector<int>> board(11111, vector<int>(555, 0));

void dfs(pair<int, int> now, int index) {
	if(now.second == m-1) {
		result += 1;
		check = true;
		return;
	}

	for(int dx = -1; dx <= 1 && !check; dx++) {
		pair<int, int> next = {now.first + dx, now.second + 1};
		if(0 <= next.first && next.first < n && next.second < m && board[next.first][next.second] == 0) {
			board[next.first][next.second] = index;
			dfs(next, index);
			if(check == true) break;
		}
	}
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		for(int j = 0; j < m; j++) {
			if(temp[j] == '.') board[i][j] = 0;
			else board[i][j] = -1;
		}
	}

	for(int i = 0; i < n; i++) {
		check = false;
		board[i][0] = i+1;
		dfs({i, 0}, i+1);
	}

	cout << result;
}