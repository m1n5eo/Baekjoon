#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, r, q, u, v, cnt;
vector<vector<int>> graph(MAX, vector<int>(0)), child(MAX, vector<int>(0));
vector<bool> check(MAX, false);
vector<int> res(MAX, 0);

int fill_res(int node) {
	int ret = 1;
	for(int cn : child[node]) ret += fill_res(cn);
	res[node] = ret;
	return ret;
}

void find_child(int p) {
	if(cnt >= n) return;
	for(int gp : graph[p]) {
		if(check[gp] == false) {
			child[p].push_back(gp);
			check[gp] = true;
			cnt += 1;
			find_child(gp);
		}
	}
}

int main() {
	FASTIO

	cin >> n >> r >> q;
	for(int i = 0; i < n-1; i++) {
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	check[r] = true;
	find_child(r);
	res[r] = fill_res(r);
	for(int i = 0; i < q; i++) {
		cin >> u;
		cout << res[u] << "\n";
	}
}