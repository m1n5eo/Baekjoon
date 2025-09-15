#include <iostream> // BOJ 2258
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2147483647

int n, m, weight, price;
vector<pair<int, int>> meat;

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.second != b.second) return a.second < b.second;
	else return a.first > b.first;
}

int solve() {
	vector<pair<int, int>> buy;
	sort(meat.begin(), meat.end(), compare);
	buy.push_back(meat[0]);
	int total = meat[0].first, sum = 0;
	for(int i = 1; i < n; i++) {
		if(meat[i-1].second != meat[i].second) {
			sum = total;
			total += meat[i].first;
			buy.push_back({total, meat[i].second});
		}
		else if(meat[i-1].second == meat[i].second) {
			total += meat[i].first;
			buy.push_back({buy[i-1].first+meat[i].first, buy[i-1].second+meat[i].second});
		}
	}
	// cout << "\n" << "buy" << "\n"; for(int i = 0; i < n; i++) cout << buy[i].first << " " << buy[i].second << "\n"; cout << "\n";
	sort(buy.begin(), buy.end(), compare);
	for(int i = 0; i < n; i++) if(buy[i].first >= m) return buy[i].second;
	return -1;
}

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> weight >> price;
		meat.push_back({weight, price});
	}
	cout << solve();
}