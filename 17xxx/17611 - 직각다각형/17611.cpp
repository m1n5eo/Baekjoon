#include <iostream> // BOJ 17611
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool compare(pair<int, int> x, pair<int, int> y) {
	if(x.first != y.first) return x.first < y.first;
	else return x.second < y.second;
}

int solve(vector<pair<int, int>> line) {
	int ret = 0, line_size = line.size();
	priority_queue<int, vector<int>, greater<int>> pq;

	sort(line.begin(), line.end(), compare);

	for(int i = 0; i < line_size; i++) {
		pair<int, int> now = line[i];

		while(!pq.empty() && pq.top() <= now.first) pq.pop();
		pq.push(now.second);
		ret = max(ret, (int)pq.size());
	}

	return ret;
}

int main() {
	FASTIO

	int n, a, b;
	vector<pair<int, int>> point;
	vector<vector<pair<int, int>>> line(2, vector<pair<int, int>>(0));

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		point.push_back({a, b});
	}

	point.push_back(point[0]);

	for(int i = 0; i < n; i++) {
		if(point[i].first == point[i+1].first) {
			if(point[i].second < point[i+1].second) line[0].push_back({point[i].second, point[i+1].second});
			else line[0].push_back({point[i+1].second, point[i].second});
		}
		else {
			if(point[i].first < point[i+1].first) line[1].push_back({point[i].first, point[i+1].first});
			else line[1].push_back({point[i+1].first, point[i].first});
		}
	}

	cout << max(solve(line[0]), solve(line[1]));
}