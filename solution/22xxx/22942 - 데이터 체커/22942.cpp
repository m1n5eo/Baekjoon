#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, x, r;
vector<pair<int, int>> circle;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

string solve() {
	priority_queue<int, vector<int>, greater<int>> pq;
	sort(circle.begin(), circle.end(), compare);
	for(int i = 0; i < n; i++) {
		if(i != 0 && circle[i].first <= pq.top() && pq.top() <= circle[i].second) return "NO";
		else pq.push(circle[i].second);
	}
	return "YES";
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> x >> r;
		circle.push_back({x-r, x+r});
	}
	cout << solve();
}