#include <iostream> // BOJ 1477
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct type {
	int change, cnt, total;
};

struct compare {
	bool operator()(type a, type b) {
		if(a.change != b.change) return a.change < b.change;
		else return a.cnt > b.cnt;
	}
};

int n, m, l, temp;
vector<int> highway;

int solve() {
	priority_queue<type, vector<type>, compare> gap;
	highway.push_back(0); highway.push_back(l);
	sort(highway.begin(), highway.end());
	for(int i = 0; i < n+1; i++) gap.push({highway[i+1] - highway[i], 1, highway[i+1] - highway[i]});
	for(int _ = 0; _ < m; _++) {
		type now = gap.top(); gap.pop();
		if(now.total%(now.cnt+1) == 0) gap.push({now.total/(now.cnt+1), now.cnt+1, now.total});
		else gap.push({now.total/(now.cnt+1)+1, now.cnt+1, now.total});
	}
	return gap.top().change;
}

int main() {
	FASTIO

	cin >> n >> m >> l;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		highway.push_back(temp);
	}
	cout << solve();
}