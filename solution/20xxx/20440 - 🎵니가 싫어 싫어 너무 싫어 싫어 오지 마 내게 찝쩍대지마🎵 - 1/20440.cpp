#include <iostream> // BOJ 20440
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000001

struct compare {
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if(a.second != b.second) return a.second > b.second;
		else return a.first > b.first;
	}
};

void solve(vector<pair<int, int>> mos) {
	int m = 0, mos_size = mos.size();
	pair<int, int> clock = {INF, -INF};
	priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;

	sort(mos.begin(), mos.end());

	for(int i = 0; i < mos_size; i++) {
		pair<int, int> now = mos[i];
		bool check = false;

		while(!pq.empty() && pq.top().second < now.first) pq.pop();
		if(!pq.empty() && m == (int)pq.size() && pq.top().second == now.first) {
			now = {pq.top().first, now.second};
			pq.pop();
			check = true;
		}
		pq.push(now);

		if(check || m < (int)pq.size()) {
			m = (int)pq.size();
			clock = {now.first, pq.top().second};
		}
	}

	cout << m << "\n";
	cout << clock.first << " " << clock.second;
}

int main() {
	FASTIO

	int n, a, b;
	vector<pair<int, int>> mosquito;

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		mosquito.push_back({a, b});
	}

	solve(mosquito);
}