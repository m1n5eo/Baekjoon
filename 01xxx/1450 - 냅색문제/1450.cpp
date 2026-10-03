#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n;
lli c, temp;
vector<lli> weight, a, b;

void left(int idx, lli sum) {
	if(idx == n/2) {
		a.push_back(sum);
		return;
	}

	left(idx+1, sum);
	left(idx+1, sum+weight[idx]);
}

void right(int idx, lli sum) {
	if(idx == n) {
		b.push_back(sum);
		return;
	}

	right(idx+1, sum);
	right(idx+1, sum+weight[idx]);
}

int solve() {
	int ret = 0;
	left(0, 0); right(n/2, 0);
	sort(b.begin(), b.end());
	for(int i = 0; i < a.size(); i++) ret += upper_bound(b.begin(), b.end(), c-a[i]) - b.begin();
	return ret;
}

int main() {
	FASTIO

	cin >> n >> c;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		weight.push_back(temp);
	}

	cout << solve();
}