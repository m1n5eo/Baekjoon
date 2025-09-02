#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

string in;

int solve() {
	int n = in.size();
	vector<int> number, dp;
	number.push_back(0);
	dp.push_back(1); dp.push_back(1);
	for(char num : in) {
		number.push_back(num-'0');
		dp.push_back(0);
	}
	for(int i = 2; i <= n; i++) {
		int determine = number[i-1]*10 + number[i];
		if(determine < 10) dp[i] = dp[i-3];
		else if(determine == 10 || determine == 20 || determine == 30) dp[i] = dp[i-2];
		else if(4 <= determine/10 && determine%10 == 0) return 0;
		else if(determine > 34) dp[i] = dp[i-1];
		else dp[i] = dp[i-1] + dp[i-2];
	}
	for(int i = 1; i <= n; i++) cout << dp[i] << " "; cout << "\n";
	return dp[n];
}

int main() {
	FASTIO

	cin >> in;
	cout << solve();
}