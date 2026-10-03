#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int solve() {
    int n, m, start, end;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>(0));
    vector<int> weight(n+1, 0);
    for(int i = 0; i < m; i++) {
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin >> start >> end;

    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    pq.push({start, INF});
    weight[start] = INF;
    while(!pq.empty()) {
        pair<int, int> now = pq.top();
        pq.pop();
        if(weight[now.first] <= now.second) {
            for(pair<int, int> g : graph[now.first]) {
                pair<int, int> next = {g.first, min(g.second, now.second)};
                if(weight[next.first] < next.second) {
                    weight[next.first] = next.second;
                    pq.push(next);
                }
            }
        }
    }
    return weight[end];
}

int main() {
    FASTIO
    cout << solve();
}