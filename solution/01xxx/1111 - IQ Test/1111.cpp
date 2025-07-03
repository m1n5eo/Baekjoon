#include <iostream> // BOJ 1111
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321

int n;
lli temp;
vector<lli> sequence;

lli solve() {
	if(n == 1) return INF;
	else if(n == 2) return (sequence[0] != sequence[1]? INF : sequence[0]);

	for(int i = 0; i < n; i++) {
		if(sequence[i] != sequence[n-1]) break;
		else if(i == n-1) return sequence[0];
	}

	if(sequence[1] - sequence[0] == 0) return -INF;
	else if((sequence[2] - sequence[1]) % (sequence[1] - sequence[0]) != 0) return -INF;

	lli s = sequence[0];
	lli a = (sequence[2] - sequence[1]) / (sequence[1] - sequence[0]);
	lli b = sequence[1] - sequence[0] * a;

	for(int i = 0; i < n-1; i++) {
		if(sequence[i] * a + b != sequence[i+1]) {
			return -INF;
		}
	}

	return sequence.back() * a + b;
}

int main() {
	FASTIO

	cin >> n;

	for(int _ = 0; _ < n; _++) {
		cin >> temp;
		sequence.push_back(temp);
	}

	lli result = solve();

	if(result == INF) cout << "A";
	else if(result == -INF) cout << "B";
	else cout << result;
}