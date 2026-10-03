#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, k, temp;
vector<int> when;

bool compare(int a, int b) {
	return a < b;
}

int solve() {
	int ret = when.size();
	vector<int> between;
	for(int i = 1; i < n; i++) between.push_back(when[i] - when[i-1] - 1);
	sort(between.begin(), between.end(), compare);
	for(int i = 0; i < n-k; i++) ret += between[i];
	return ret;
}

int main() {
	FASTIO

	cin >> n >> k;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		when.push_back(temp);
	}

	cout << solve();
}