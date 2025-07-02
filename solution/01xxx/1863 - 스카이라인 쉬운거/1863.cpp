#include <iostream> // BOJ 1863
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1111111

bool compare(pair<int, int> x, pair<int, int> y) {
	return x.first < y.first;
}

int main() {
	FASTIO
	
	int n, a, b, count = 0;
	vector<pair<int, int>> skyline;
	stack<int> st;

	cin >> n;

	for(int _ = 0; _ < n; _++) {
		cin >> a >> b;
		skyline.push_back({a, b});
	}

	skyline.push_back({0, 0});
	skyline.push_back({INF, 0});
	sort(skyline.begin(), skyline.end(), compare);

	for(pair<int, int> s: skyline) {
		if(st.size() == 0 || st.top() < s.second) {
			st.push(s.second);
		}
		else if(st.top() > s.second) {
			while(st.top() > s.second) {
				int k = st.top();
				while(k == st.top()) st.pop();
				count += 1;
			}
			st.push(s.second);
		}
	}

	cout << count;
}