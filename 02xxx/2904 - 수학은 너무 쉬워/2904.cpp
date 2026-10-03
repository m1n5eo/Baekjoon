#include <iostream> // BOJ 2904
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

long long int expo(int base, int exp) {
	long long int res = 1;
	while(exp) {
		if(exp % 2) res *= base;
		base *= base;
		exp /= 2;
	}
	return res;
}

int main() {
	FASTIO

	vector<int> prime;
	vector<bool> check(MAX, true);

	for(int i = 2; i < MAX; i++) {
		if(check[i] == true) {
			prime.push_back(i);
			for(int j = i*2; j < MAX; j+=i) {
				check[j] = false;
			}
		}
	}
	
	int n, temp;
	vector<int> paper;
	pair<long long int, int> result = {1, 0};
	vector<vector<int>> decimal(111, vector<int>(0));

	cin >> n;

	for(int i = 0; i < n; i++) {
		cin >> temp;
		paper.push_back(temp);
	}

	for(int i = 0; i < prime.size(); i++) {
		int cnt = 0;
		for(int j = 0; j < n; j++) {
			int p = paper[j], c = 0;
			while(p % prime[i] == 0) {
				p /= prime[i];
				c += 1;
			}
			decimal[j].push_back(c);
			cnt += c;
		}

		int k = cnt / n;
		result.first *= expo(prime[i], k);

		for(int j = 0; j < n && k != 0; j++) {
			if(decimal[j][i] < k) {
				result.second += (k - decimal[j][i]);
			}
		}
	}
	
	cout << result.first << " " << result.second;
}