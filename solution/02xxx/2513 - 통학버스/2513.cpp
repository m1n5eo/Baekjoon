#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>

struct compare1 {
	bool operator() (pii &a, pii &b) {
		return a.first > b.first;
	}
};

struct compare2 {
	bool operator() (pii &a, pii &b) {
		return a.first < b.first;
	}
};

int main() {
	FASTIO

	int n, k, s, x, p, result = 0;
	priority_queue<pii, vector<pii>, compare1> left;
	priority_queue<pii, vector<pii>, compare2> right;

	cin >> n >> k >> s;

	for(int i = 0; i < n; i++) {
		cin >> x >> p;

		if(x < s) left.push({x, p});
		if(x > s) right.push({x, p});
	}

	while(left.size()) {
		int capacity = k;
		int dist = s - left.top().first;

		if(capacity - left.top().second > 0) {
			while(capacity > 0 && left.size()) {
				if(capacity - left.top().second >= 0) {
					capacity -= left.top().second;
					left.pop();
				}
				else {
					pii now = left.top();
					left.pop();

					now.second -= capacity;
					capacity = 0;

					left.push(now);
				}
			}
		}
		else if(capacity - left.top().second == 0) {
			capacity -= left.top().second;
			left.pop();
		}
		else if(capacity - left.top().second < 0) {
			pii now = left.top();
			left.pop();

			now.second -= capacity;
			capacity = 0;

			left.push(now);
		}

		result += dist*2;
	}

	while(right.size()) {
		int capacity = k;
		int dist = right.top().first - s;

		if(capacity - right.top().second > 0) {
			while(capacity > 0 && right.size()) {
				if(capacity - right.top().second >= 0) {
					capacity -= right.top().second;
					right.pop();
				}
				else {
					pii now = right.top();
					right.pop();

					now.second -= capacity;
					capacity = 0;

					right.push(now);
				}
			}
		}
		else if(capacity - right.top().second == 0) {
			capacity -= right.top().second;
			right.pop();
		}
		else if(capacity - right.top().second < 0) {
			pii now = right.top();
			right.pop();

			now.second -= capacity;
			capacity = 0;

			right.push(now);
		}

		result += dist*2;
	}

	cout << result;
}