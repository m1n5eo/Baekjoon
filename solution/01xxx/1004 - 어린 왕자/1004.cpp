#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int dist(pair<int, int> a, pair<int, int> b) {
	return (a.first - b.first)*(a.first - b.first) + (a.second - b.second)*(a.second - b.second);
}

int main() {
	FASTIO

	int testcase;
	cin >> testcase;

	for(int tc = 0; tc < testcase; tc++) {
		pair<int, int> start, stop;
		int n, x, y, radius, result = 0;

		cin >> start.first >> start.second >> stop.first >> stop.second;
		cin >> n;

		for(int i = 0; i < n; i++) {
			cin >> x >> y >> radius;

			if(dist(start, {x, y}) < radius*radius && dist(stop, {x, y}) < radius*radius) continue;
			if(dist(start, {x, y}) < radius*radius) result += 1;
			if(dist(stop, {x, y}) < radius*radius) result += 1;
		}

		cout << result << "\n";
	}
}