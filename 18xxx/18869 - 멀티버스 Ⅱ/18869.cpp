#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 10001

bool compare1(pair<int, int> a, pair<int, int> b) {
	if(a.first != b.first) return a.first < b.first;
	else return a.second < b.second;
}

bool compare2(vector<int> a, vector<int> b) {
	int siz = a.size();
	for(int i = 0; i < siz; i++) {
		if(a[i] != b[i]) return a[i] < b[i];
	}
	return false;
}

int n, m, temp;
vector<vector<pair<int, int>>> planet;
vector<vector<int>> comp;
vector<int> ssang(MAX, 0);

int solve() {
	int ret = 0, cnt = 0;
	for(int i = 1; i < MAX; i++) ssang[i] = ssang[i-1] + i;

	for(int i = 0; i < n; i++) {
		sort(planet[i].begin(), planet[i].end(), compare1);
		comp.push_back(vector<int>(0));
		for(int j = 0; j < m-1; j++) {
			if(planet[i][j].first == planet[i][j+1].first) planet[i][j+1].second = planet[i][j].second;
			comp[i].push_back(planet[i][j].second);
		}
	}

	sort(comp.begin(), comp.end(), compare2);
	comp.push_back(vector<int>(m-1, -1));

	for(int i = 0; i < n; i++) {
		if(comp[i] == comp[i+1]) cnt += 1;
		else if(comp[i] != comp[i+1]) {
			ret += ssang[cnt];
			cnt = 0;
		}
	}

	return ret;
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		planet.push_back(vector<pair<int, int>>(0));
		for(int j = 0; j < m; j++) {
			cin >> temp;
			planet[i].push_back({temp, j});
		}
	}

	cout << solve();
}