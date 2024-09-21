#include <bits/stdc++.h>
using namespace std;

pair <int, int> p[1000001];
vector <long long> v;
stack <pair<int, int>> st;

int main() {

	int a,n;
	scanf("%d",&n);
	v.push_back(-9876543210);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d",&a);
		if (v.back() < a) {
			v.push_back(a);
			cnt++;
			p[i] = { cnt,a };
		}
		else {
			int idx = lower_bound(v.begin(), v.end(), a) - v.begin();
			v[idx] = a;
			p[i] = { idx ,a };
		}
	}
	int key = cnt;
	for (int i = n - 1; i >= 0; i--) {
		if (key == p[i].first) {
			st.push(p[i]);
			key--;
			if (key < 1) break;
		}
	}
	printf("%d\n",cnt);
	while (!st.empty()) {
		printf("%d ",st.top().second);
		st.pop();
	}

}