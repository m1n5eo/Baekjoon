#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define INF 1234567890
#define MAX 22222

int main() {
	FASTIO

	int n, m, s, a, b, d;
	vector<int> dist(MAX, INF);
	vector<vector<pii>> node(MAX, vector<pii>(0));
	priority_queue<pii> pq;

    cin >> n >> m >> s;

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        node[a].push_back({b, d});
    }

    pq.push({0, s});
    
    while(pq.size()) {
        int now = pq.top().second;
        int now_dist = -pq.top().first;

        pq.pop();

        if(dist[now] < now_dist) {
            continue;
        }

        int len = node[now].size();

        for(int i = 0; i < len; i++) {
            int next = node[now][i].first;
            int next_dist = now_dist + node[now][i].second;

            if(next_dist < dist[next]) {
                dist[next] = next_dist;
                pq.push({-next_dist, next});
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        if(i == s) cout << 0 << "\n";
        else if(dist[i] == INF) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}