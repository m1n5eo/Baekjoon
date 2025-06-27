#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890
#define left first
#define right second

bool compare(pair<int, int> a, pair<int, int> b) {
	if(a.left != b.left) return a.left < b.left;
	return a.right < b.right;
}

int main() {
	FASTIO

	int n, l, r, result = 0;
	vector<pair<int, int>> schedule;
	priority_queue<int, vector<int>, greater<int>> now;
	pair<int, int> cal = {INF, -INF};

	cin >> n;

	for(int _ = 0; _ < n; _++) {
		cin >> l >> r;
		schedule.push_back({l, r});
	}

	sort(schedule.begin(), schedule.end(), compare);
	
	for(int i = 0; i < n; i++) {
		if(i == 0) {
			now.push(schedule[i].right);
			cal = schedule[i];
		}
		else if(now.top() >= schedule[i].left) {
			now.push(schedule[i].right);
			cal.right = max(cal.right, schedule[i].right);
		}
		else if(now.top() < schedule[i].left && cal.right+1 >= schedule[i].left) {
			now.pop();
			now.push(schedule[i].right);
			cal.right = max(cal.right, schedule[i].right);
		}
		else {
			result += (cal.right - cal.left + 1) * now.size();
			while(now.size()) now.pop();
			now.push(schedule[i].right);
			cal = schedule[i];
		}
	}

	cout << result + (cal.right - cal.left + 1) * now.size();
}