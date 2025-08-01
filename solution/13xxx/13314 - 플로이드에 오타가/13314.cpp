#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
	FASTIO

	int n = 100;

	cout << n << " ";
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j) cout << 0 << " ";
			else if(i == n || j == n) cout << 1 << " ";
			else cout << 10000 << " ";
		}
		cout << "\n";
	}
}