#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11111

int n;
vector<int> prime, vec;
vector<bool> check(MAX, true);

int solve() {
	for(int v : vec) {
		if(n < v) return v;
	}
}

int main() {
	FASTIO

	check[0] = false; check[1] = false;
	for(int i = 2; i < MAX; i++) {
		if(check[i] == true) {
			prime.push_back(i);
			for(int j = i*2; j < MAX; j+=i) check[j] = false;
		}
	}

	int prime_size = prime.size();
	for(int i = 0; i < prime_size-1; i++) {
		vec.push_back(prime[i] * prime[i+1]);
	}

	cin >> n;
	cout << solve();
}