#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890

struct type {
    lli node, sum, big;
};

struct compare {
    bool operator()(type a, type b) {
        return a.sum-a.big > b.sum-b.big;
    }
};

lli solve() {
    lli n, s, e;
    cin >> n >> s >> e;
    vector<vector<pair<lli, lli>>> graph(n+1, vector<pair<lli, lli>>(0));
    vector<bool> visit(n+1, false);
    for(lli i = 0; i < n-1; i++) {
        lli a, b, l; cin >> a >> b >> l;
        graph[a].push_back({b, l});
        graph[b].push_back({a, l});
    }

    if(s == e) return 0;

    lli ret = INF;
    priority_queue<type, vector<type>, compare> bfs;
    bfs.push({s, 0, 0});
    while(!bfs.empty()) {
        type now = bfs.top();
        bfs.pop();
        visit[now.node] = true;
        for(pair<lli, lli> g : graph[now.node]) {
            type next = {g.first, now.sum + g.second, max(now.big, g.second)};
            if(next.node == e) ret = min(ret, next.sum - next.big);
            else if(visit[next.node] == false) bfs.push(next);
        }
    }
    return (ret != INF? ret : 0);
}

int main() {
    FASTIO
    cout << solve();
}