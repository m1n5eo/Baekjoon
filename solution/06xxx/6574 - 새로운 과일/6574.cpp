#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 101

string a, b;

string solve() {
	vector<vector<int>> dp(MAX, vector<int>(MAX, 0));
	int as = a.size();
	int bs = b.size();
	a = "!" + a;
	b = "!" + b;
	for(int i = 1; i <= as; i++) {
		for(int j = 1; j <= bs; j++) {
			if(a[i] == b[j]) dp[i][j] = dp[i-1][j-1]+1;
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	string LCS;
	int k = dp[as][bs];
	while(k != 0) {
		if(dp[as-1][bs] == k) as -= 1;
		else if(dp[as][bs-1] == k) bs -= 1;
		else {
			LCS = a[as] + LCS;
			as -= 1;
			bs -= 1;
			k -= 1;
		}
	}
	string ret;
	int i = 1, j = 1; k = 0;
	as = a.size(); bs = b.size();
	while(i < as && j < bs) {
		if(k < dp[as-1][bs-1] && a[i] != b[j] && a[i] == LCS[k]) {
			ret += b[j];
			j += 1;
		}
		else if(k < dp[as-1][bs-1] && a[i] != b[j] && b[j] == LCS[k]) {
			ret += a[i];
			i += 1;
		}
		else if(k < dp[as-1][bs-1] && a[i] == b[j] && b[j] == LCS[k]) {
			ret = ret + LCS[k];
			i += 1;
			j += 1;
			k += 1;
		}
		else {
			ret = ret + a[i] + b[j];
			i += 1;
			j += 1;
		}
	}
	while(i < as) ret += a[i++];
	while(j < bs) ret += b[j++];
	return ret;
}

int main() {
	FASTIO
	while(cin >> a >> b) cout << solve() << "\n";
}