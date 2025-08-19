#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 301

int n, m, d, p;
vector<int> day(1, 0), page(1, 0), dp(MAX, 0);

int main() {
	FASTIO

	cin >> n >> m;
	for(int i = 1; i <= m; i++) {
		cin >> d >> p;
		day.push_back(d);
		page.push_back(p);
	}

	for(int i = 1; i <= m; i++)
		for(int j = n; j >= day[i]; j--)
			dp[j] = max(dp[j], dp[j-day[i]] + page[i]);

	cout << dp[n];
}