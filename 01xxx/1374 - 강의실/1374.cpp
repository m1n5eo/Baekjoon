#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, t, l, r;
vector<pair<int, int>> study;
priority_queue<int, vector<int>, greater<int>> now;

bool compare(pair<int, int> a, pair<int, int> b) {
	return a.first < b.first;
}

int solve() {
	int ret = 0;
	sort(study.begin(), study.end(), compare);
	for(int i = 0; i < n; i++) {
		if(!now.empty() && study[i].first >= now.top()) now.pop();
		now.push(study[i].second);
		ret = max(ret, (int)now.size());
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> t >> l >> r;
		study.push_back({l, r});
	}

	cout << solve();
}