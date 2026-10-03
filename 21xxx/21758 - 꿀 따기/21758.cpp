#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int n, temp;
vector<int> honey(1, 0), prefix(1, 0);

int solve() {
	int ret = 0;
	for(int i = 2; i <= n-1; i++) {
		ret = max(ret, prefix[n-1] - honey[1] + honey[i]); // 벌통이 가운데
		ret = max(ret, (prefix[n-1] - honey[i]) + (prefix[i-1])); // 벌통이 제일 왼쪽
		ret = max(ret, (prefix[n] - honey[1] - honey[i]) + (prefix[n] - prefix[i])); // 벌통이 제일 오른쪽
	}
	return ret;
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 1; i <= n; i++) {
		cin >> temp;
		honey.push_back(temp);
		prefix.push_back(prefix.back() + temp);
	}

	cout << solve();
}