#include <bits/stdc++.h>
using namespace std;

int n, temp, cnt;
pair<int,int> p[1001];
vector<long long> v;
stack<pair<int, int>> st;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

	cin >> n;
	v.push_back(-1);
	for(int i = 0; i < n; i++) {
		cin >> temp;
		if(v.back() < temp) {
			v.push_back(temp);
			cnt++;
			p[i] = {cnt, temp};
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), temp) - v.begin();
			v[idx] = temp;
			p[i] = {idx, temp};
		}
	}

	int key = cnt;
	for(int i = n-1; i >= 0; i--) {
		if(key == p[i].first) {
			st.push(p[i]);
			key--;
			if(key < 1) break;
		}
	}

	cout << cnt << "\n";
	while(!st.empty()) {
        cout << st.top().second << " ";
		st.pop();
	}
}