#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2147483647

struct type {
    int index, dist, sw;
};

struct comparefox {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.second != b.second) return a.second > b.second;
        else return a.first > b.first;
    }
};

struct comparewolf {
    bool operator()(type a, type b) {
        if(a.dist != b.dist) return a.dist > b.dist;
        else return a.index > b.index;
    }
};

int solve() {
    int n, m, a, b, d;
    cin >> n >> m;
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>(0));
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        graph[a].push_back({b, d*2});
        graph[b].push_back({a, d*2});
    }
    
    vector<int> fox(n+1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, comparefox> pqfox;
    pqfox.push({1, 0});
    fox[1] = 0;
    while(!pqfox.empty()) {
        pair<int, int> now = pqfox.top();
        pqfox.pop();
        if(fox[now.first] < now.second) continue;
        int graph_size = graph[now.first].size();
        for(int i = 0; i < graph_size; i++) {
            pair<int, int> next = {graph[now.first][i].first, now.second + graph[now.first][i].second};
            if(fox[next.first] > next.second) {
                fox[next.first] = next.second;
                pqfox.push(next);
            }
        }
    }

    // cout << "\n" << "fox" << "\n";
    // for(int i = 1; i <= n; i++) cout << fox[i] << " ";
    // cout << "\n";

    vector<vector<int>> wolf(n+1, vector<int>(2, INF));
    priority_queue<type, vector<type>, comparewolf> pqwolf;
    pqwolf.push({1, 0, 0});
    wolf[1][0] = 0;
    while(!pqwolf.empty()) {
        type now = pqwolf.top();
        pqwolf.pop();
        if(wolf[now.index][now.sw] < now.dist) continue;
        int graph_size = graph[now.index].size();
        for(int i = 0; i < graph_size; i++) {
            type next = {graph[now.index][i].first, now.dist, 1-now.sw};
            if(now.sw == 0) next.dist += graph[now.index][i].second/2;
            else next.dist += graph[now.index][i].second*2;
            if(wolf[next.index][next.sw] > next.dist) {
                wolf[next.index][next.sw] = next.dist;
                pqwolf.push(next);
            }
        }
    }

    // cout << "\n" << "wolf" << "\n";
    // for(int i = 1; i <= n; i++) cout << wolf[i][0] << " ";
    // cout << "\n";
    // for(int i = 1; i <= n; i++) cout << wolf[i][1] << " ";
    // cout << "\n";

    int ret = 0;
    for(int i = 2; i <= n; i++) if(fox[i] < min(wolf[i][0], wolf[i][1])) ret += 1;
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}