#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n;
string bracket;

int solve() {
	int ret = 0;
	stack<int> st;
	vector<int> vec;
	for(int i = 0; i < n; i++) {
		vec.push_back(0);
		if(bracket[i] == '(') st.push(i);
		else if(bracket[i] == ')' && !st.empty()) {
			if(st.top() > 0) ret = max(ret, i-st.top()+1+vec[st.top()-1]);
			else ret = max(ret, i-st.top()+1);
			vec[i] = i-st.top()+1;
			if(i-vec[i] >= 0 && vec[i-vec[i]] != 0) vec[i] += vec[i-vec[i]];
			st.pop();
		}
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n >> bracket;
	cout << solve();
}