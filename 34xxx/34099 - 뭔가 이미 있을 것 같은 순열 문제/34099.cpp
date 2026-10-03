#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int t, n, k;

int main() {
	FASTIO

	cin >> t;
	for(int tc = 1; tc <= t; tc++) {
		cin >> n >> k;
		if(n <= k || k != 1) {
			for(int i = 1; i <= n; i++) cout << i << " ";
		}
		else if((n == 2 || n == 3) && k == 1) cout << -1;
		else if(n != 2 && k == 1) {
			for(int i = 2; i <= n; i+=2) cout << i << " ";
			for(int i = 1; i <= n; i+=2) cout << i << " ";
		}
		else cout << -1;
		cout << "\n";
	}
}