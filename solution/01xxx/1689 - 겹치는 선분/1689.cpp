#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, l, r;
vector<pair<int, int>> coordinate;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int solve() {
	priority_queue<int, vector<int>, greater<int>> pq;
	sort(coordinate.begin(), coordinate.end(), compare);
	for(int i = 0; i < n; i++) {
		if(i != 0 && pq.top() <= coordinate[i].first) pq.pop();
		pq.push(coordinate[i].second);
	}
	return pq.size();
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		coordinate.push_back({l, r});
	}
	cout << solve();
}