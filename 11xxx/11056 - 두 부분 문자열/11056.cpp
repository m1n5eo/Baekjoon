#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1001

string a, b;
vector<vector<int>> dp(MAX, vector<int>(MAX, 0));

int solve() {
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
	return a.size() + b.size() - dp[as][bs] - 2;
}

int main() {
	FASTIO
	
	cin >> a;
	cin >> b;
	cout << solve();
}