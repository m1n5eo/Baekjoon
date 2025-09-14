#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

lli n, k;

string solve() {
	if(n == 1 && k == 2) return "YES";
	lli start = 0, end = n/2;
	while(start < end) {
		lli mid = (start+end)/2;
		if((mid+1)*(n-mid+1) == k || (start+1)*(n-start+1) == k || (end+1)*(n-end+1) == k) return "YES";
		else if((mid+1)*(n-mid+1) > k) end = mid-1;
		else if((mid+1)*(n-mid+1) < k) start = mid+1;
	}
	return "NO";
}

int main() {
	FASTIO

	cin >> n >> k;
	cout << solve();
}