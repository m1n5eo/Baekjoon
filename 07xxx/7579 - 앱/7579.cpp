#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int n, m, k, temp;
vector<int> memory(1, 0), cost(1, 0), dp(MAX, 0);

int solve() {
	for(int i = 1; i <= n; i++) for(int j = k; j >= cost[i]; j--) dp[j] = max(dp[j], dp[j-cost[i]] + memory[i]);
	for(int i = 0; i <= k; i++) if(dp[i] >= m) return i;
}

int main() {
	FASTIO
	
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		cin >> temp;
		memory.push_back(temp);
	}
	for(int i = 0; i < n; i++) {
		cin >> temp;
		cost.push_back(temp);
		k += temp;
	}

	cout << solve();
}