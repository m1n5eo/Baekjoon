#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, m, l, r;
vector<pair<int, int>> water;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else a.second < b.second;
}

int solve() {
	int ret = 0;
	vector<pair<int, int>> now;
	sort(water.begin(), water.end(), compare);
	for(int i = 0; i < n; i++) {
		int k = (i == 0 || (now.back().second - now.back().first + 1) % m == 0? m : (now.back().second - now.back().first + 1) % m);
		if(i == 0 || now.back().second + m - k < water[i].first) now.push_back(water[i]);
		else now.back().second = water[i].second;
	}
	for(pair<int, int> plank : now) ret += (plank.second - plank.first) / m + 1;
	return ret;
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		water.push_back({l, r-1});
	}
	cout << solve();
}