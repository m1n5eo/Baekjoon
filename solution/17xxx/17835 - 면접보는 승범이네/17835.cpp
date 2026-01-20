#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321

struct pqcmp {
    bool operator()(pair<lli, lli> a, pair<lli, lli> b) {
        if(a.second != b.second) return a.second > b.second;
        else return a.first > b.first;
    }
};

pair<lli, lli> solve() {
    lli n, m, k;
    cin >> n >> m >> k;
    vector<vector<pair<lli, lli>>> graph(n+1, vector<pair<lli, lli>>(0));
    priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, pqcmp> pq;
    vector<lli> dist(n+1, INF);
    for(lli _ = 0; _ < m; _++) {
        lli a, b, c; cin >> a >> b >> c;
        graph[b].push_back({a, c});
    }
    for(lli _ = 0; _ < k; _++) {
        lli a; cin >> a;
        dist[a] = 0;
        pq.push({a, 0});
    }

    while(!pq.empty()) {
        pair<lli, lli> now = pq.top(); pq.pop();
        if(dist[now.first] < now.second) continue;
        for(pair<lli, lli> dnext : graph[now.first]) {
            pair<lli, lli> next = {dnext.first, dnext.second+now.second};
            if(next.second < dist[next.first]) {
                dist[next.first] = next.second;
                pq.push(next);
            }
        }
    }

    pair<lli, lli> ret = {1, dist[1]};
    for(lli i = 2; i <= n; i++) {
        if(ret.second < dist[i]) {
            ret = {i, dist[i]};
        }
    }
    return ret;
}

int main() {
    FASTIO
    pair<lli, lli> sol = solve();
    cout << sol.first << "\n" << sol.second;
}