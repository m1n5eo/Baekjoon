#include <iostream>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
	FASTIO

	int n, w, l, temp, weight = 0, count = 0;
	queue<int> now, wait;

	cin >> n >> w >> l;

	for(int _ = 0; _ < n; _++) {
		cin >> temp;
		wait.push(temp);
	}

	for(int _ = 0; _ < w; _++) {
		now.push(0);
	}

	for(count = 0; wait.size() + weight; count++) {
		weight -= now.front();
		now.pop();

		if(wait.size() && weight + wait.front() <= l) {
			now.push(wait.front());
			weight += wait.front();
			wait.pop();
		}
		else now.push(0);
	}

	cout << count;
}