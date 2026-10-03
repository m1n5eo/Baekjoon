#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11

int n, m, h, result;
vector<vector<int>> village(MAX, vector<int>(MAX, 0));
pair<int, int> home;
vector<pair<int, int>> mint;
vector<bool> visit(MAX, false);

void solve(pair<int, int> now, int health, int cnt) {
	if(cnt <= mint.size() && abs(now.first - home.first) + abs(now.second - home.second) <= health) result = max(result, cnt);
	if(cnt == mint.size()) return;
	for(int i = 0; i < mint.size(); i++) {
		int dist = abs(now.first - mint[i].first) + abs(now.second - mint[i].second);
		if(visit[i] == false && health - dist >= 0) {
			visit[i] = true;
			solve(mint[i], health - dist + h, cnt+1);
			visit[i] = false;
		}
	}
}

int main() {
	FASTIO

	cin >> n >> m >> h;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> village[i][j];
			if(village[i][j] == 1) home = {i, j};
			else if(village[i][j] == 2) mint.push_back({i, j});
		}
	}

	solve(home, m, 0);
	cout << result;
}