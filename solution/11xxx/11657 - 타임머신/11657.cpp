#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321
#define MAX 555

struct type {
	lli start, end, time;
};

lli n, m, a, b, c;
vector<type> bus;

vector<lli> solve() {
	vector<lli> dist(MAX, INF), ret;
	dist[1] = 0;
	for(lli round = 0; round < n; round++) {
		for(lli i = 0; i < m; i++) {
			type now = bus[i];
			if(dist[now.start] != INF && dist[now.end] > dist[now.start] + now.time) {
				dist[now.end] = dist[now.start] + now.time;
				if(round == n-1) return {-1};
			}
		}
	}
	for(lli i = 2; i <= n; i++) ret.push_back(dist[i] != INF? dist[i] : -1);
	return ret;
}

int main() {
	FASTIO

	cin >> n >> m;
	for(lli i = 0; i < m; i++) {
		cin >> a >> b >> c;
		bus.push_back({a, b, c});
	}
	for(lli s : solve()) cout << s << "\n";
}