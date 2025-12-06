#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

struct type {
    int start, end, cost;
};

deque<int> solve() {
    int n, m;
    cin >> n >> m;
    vector<type> alley;
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        alley.push_back({a, b, c});
    }

    vector<pair<int, int>> dist(n+1, {-INF, 0});
    dist[1] = {0, 0};
    for(int round = 0; round < n; round++) {
        for(int i = 0; i < m; i++) {
            type now = alley[i];
            if(dist[now.start].first != -INF && dist[now.end].first < dist[now.start].first + now.cost) {
                dist[now.end].first = dist[now.start].first + now.cost;
                dist[now.end].second = now.start;
                if(round == n-1) dist[now.end].first = INF;
            }
        }
        // cout << "\n" << "dist.first : ";
        // for(pair<int, int> d : dist) cout << d.first << " ";
    }

    if(dist[n].first == INF) return {-1};
    else if(dist[n].first == -INF) return {-1};
    
    deque<int> ret;
    int idx = n;
    while(idx != 1) {
        ret.push_front(idx);
        idx = dist[idx].second;
    }
    ret.push_front(1);
    return ret;
}

int main() {
    FASTIO
    deque<int> sol = solve();
    for(int s : sol) cout << s << " ";
}