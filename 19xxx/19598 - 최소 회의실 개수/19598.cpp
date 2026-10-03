#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, l, r;
vector<pair<int, int>> meeting;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

int solve() {
	priority_queue<int, vector<int>, greater<int>> pq;
	sort(meeting.begin(), meeting.end(), compare);
	for(int i = 0; i < n; i++) {
		if(pq.size() && pq.top() <= meeting[i].first) pq.pop();
		pq.push(meeting[i].second);
	}
	return pq.size();
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		meeting.push_back({l, r});
	}
	cout << solve();
}