#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321
#define MAX 555

struct type {
	lli start, end, cost;
};

string solve() {
	lli n, m, w, s, e, t;
	vector<type> route;
	cin >> n >> m >> w;
	vector<int> save, check(n+1, false);
	for(lli i = 0; i < m; i++) {
		cin >> s >> e >> t;
		route.push_back({s, e, t});
		route.push_back({e, s, t});
	}
	for(lli i = 0; i < w; i++) {
		cin >> s >> e >> t;
		route.push_back({s, e, -t});
		if(s == e) return "YES";
		else if(check[s] == false) {
			save.push_back(s);
			check[s] = true;
		}
	}
	for(int sv : save) {
		vector<lli> dist(n+1, INF);
		dist[sv] = 0;
		for(lli round = 0; round < n; round++) {
			for(type now : route) {
				if(dist[now.start] != INF && dist[now.start] + now.cost < dist[now.end]) {
					dist[now.end] = dist[now.start] + now.cost;
					if(round == n-1) return "YES";
				}
			}
		}
	}
	return "NO";
}

int main() {
	FASTIO
	int tc; cin >> tc;
	while(tc--) cout << solve() << "\n";
}