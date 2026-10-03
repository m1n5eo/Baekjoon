#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 44

string a, b;
vector<vector<int>> LCS(MAX, vector<int>(MAX, 0));

string solve() {
	string ret = "";
	int as = a.size();
	int bs = b.size();
	a = "!" + a;
	b = "!" + b;
	for(int i = 1; i <= as; i++) {
		for(int j = 1; j <= bs; j++) {
			if(a[i] == b[j]) LCS[i][j] = LCS[i-1][j-1] + 1;
			else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	int k = LCS[as][bs];
	while(k != 0) {
		if(LCS[as-1][bs] == k) as -= 1;
		else if(LCS[as][bs-1] == k) bs -= 1;
		else {
			ret = a[as] + ret;
			as -= 1;
			bs -= 1;
			k -= 1;
		}
	}
	return ret;
}

int main() {
	FASTIO
	
	cin >> a;
	cin >> b;
	cout << solve();
}