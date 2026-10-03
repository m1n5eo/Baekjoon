#include <iostream> // BOJ 16437
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define now first
#define next second
#define MAX 123457

int n, amount, connect;
string animal;
vector<pair<int, vector<int>>> tree(MAX, {0, vector<int>(0)});

lli solve(int idx) {
	lli ret = tree[idx].now;
	for(int ne: tree[idx].next) ret += solve(ne);
	return ret > 0? ret : 0;
}

int main() {
	FASTIO

	cin >> n;
	for(int i = 2; i <= n; i++) {
		cin >> animal >> amount >> connect;
		tree[i].now = (animal == "S"? amount : -amount);
		tree[connect].next.push_back(i);
	}

	cout << solve(1);
}