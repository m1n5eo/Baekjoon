#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string equation;

string solve() {
	string ret = "";
	stack<char> st;
	for(char e : equation) {
		if('A' <= e && e <= 'Z') ret += e;
		else if(e == '(') st.push(e);
		else if(e == ')') {
			while(!st.empty() && st.top() != '(') {
				ret += st.top();
				st.pop();
			}
			st.pop();
		}
		else if(e == '+' || e == '-') {
			while(!st.empty() && st.top() != '(') {
				ret += st.top();
				st.pop();
			}
			st.push(e);
		}
		else if(e == '*' || e == '/') {
			while(!st.empty() && (st.top() == '*' || st.top() == '/')) {
				ret += st.top();
				st.pop();
			}
			st.push(e);
		}
	}
	while(!st.empty()) {
		ret += st.top();
		st.pop();
	}
	return ret;
}

int main() {
	FASTIO
	
	cin >> equation;
	cout << solve();
}