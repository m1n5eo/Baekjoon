#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, l, r;
vector<pair<int, int>> wall;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int solve() {
	priority_queue<int> pq;
	sort(wall.begin(), wall.end(), compare);
	for(int i = 0; i < n+m; i++) {
		if(i != 0 && wall[i].second < pq.top()) continue;
		else if(i != 0 && pq.top() >= wall[i].first) pq.pop();
		pq.push(wall[i].second);
	}
	return pq.size();
}

int main() {
	FASTIO

	cin >> n;
	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> l >> r;
		wall.push_back({l, r});
	}
	for(int i = 1; i <= n; i++) wall.push_back({i, i});
	cout << solve();
}