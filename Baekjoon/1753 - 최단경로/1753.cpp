#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

#define NUM 22222

int n, m, s, dist[NUM];
vector<pair<int, int>> node[NUM];
priority_queue<pair<int, int>> pq;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> s;
    for(int i = 0; i < m; i++) {
        int a, b, d;

        cin >> a >> b >> d;

        node[a].push_back({b, d});
    }

    for(int i = 1; i <= n; i++) {
        dist[i] = 1234567890;
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
        else if(dist[i] == 1234567890) cout << "INF" << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}