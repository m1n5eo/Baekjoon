#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli n, s, temp;
vector<lli> sequence, a;
map<lli, lli> m;

void left(lli idx, lli sum) {
	if(idx == n/2) {
		if(m.find(sum) != m.end()) m[sum] += 1;
		else m[sum] = 1;
		return;
	}

	left(idx+1, sum+sequence[idx]);
	left(idx+1, sum);
}

void right(lli idx, lli sum) {
	if(idx == n) {
		a.push_back(sum);
		return;
	}

	right(idx+1, sum+sequence[idx]);
	right(idx+1, sum);
}

lli solve() {
	lli ret = 0;
	left(0, 0); right(n/2, 0);
	for(lli x : a) if(m.find(s-x) != m.end()) ret += m[s-x];
	return ret-(s == 0? 1:0);
}

int main() {
	FASTIO

	cin >> n >> s;
	for(lli i = 0; i < n; i++) {
		cin >> temp;
		sequence.push_back(temp);
	}

	cout << solve();
}