#include <iostream> // BOJ 14727
#include <vector>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n, temp;
vector<lli> histogram;

lli solve() {
	stack<int> st;
	lli ret = 0;

	for(int i = 1; i <= n+1; i++) {
		while(!st.empty() && histogram[st.top()] >= histogram[i]) {
			int now = st.top();
			st.pop();
			lli width = i-1 - (st.empty()? 0 : st.top());
			ret = max(ret, histogram[now] * width);
		}
		st.push(i);
	}

	return ret;
}

int main() {
	FASTIO

	cin >> n;
	histogram = vector<lli>(n+2, 0);
	for(int i = 1; i <= n; i++) {
		cin >> histogram[i];
	}

	cout << solve();
}