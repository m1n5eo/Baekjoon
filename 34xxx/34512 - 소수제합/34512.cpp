#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 2222222

void solve(int n) {
	if(n <= 6) {
		if(n == 2) cout << "-1";
		else if(n == 3) cout << "2 5 29";
		else if(n == 4) cout << "2 2 3 17";
		else if(n == 5) cout << "2 2 2 3 3";
		else if(n == 6) cout << "2 2 3 3 3 5";
		return;
	}
	for(int i = n%2? 1:2; i < n; i+=2) {
		if(i*4 % 3 == 0) {
			for(int _ = 0; _ < i; _++) cout << 2 << " ";
			for(int _ = 0; _ < n-i; _++) cout << 3 << " ";
			return;
		}
	}
}

int main() {
	FASTIO
	int n; cin >> n;
	solve(n);
}