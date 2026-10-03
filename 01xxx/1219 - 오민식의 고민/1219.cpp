#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 1234567890987654321
#define MAX 22222222

struct type {
    lli start, end, cost;
};

string solve() {
    lli n, s, e, m;
    cin >> n >> s >> e >> m;
    vector<type> trans;
    vector<lli> plus;
    for(lli i = 0; i < m; i++) {
        lli a, b, c; cin >> a >> b >> c;
        trans.push_back({a, b, c});
    }
    for(lli i = 0; i < n; i++) {
        lli temp; cin >> temp;
        plus.push_back(temp);
    }

    vector<vector<pair<lli, lli>>> graph(n, vector<pair<lli, lli>>(0));
    for(lli i = 0; i < m; i++) trans[i] = {trans[i].start, trans[i].end, -trans[i].cost+plus[trans[i].end]};

    vector<lli> dist(n, -INF);
    dist[s] = plus[s];
    for(lli round = 0; round < n*2; round++) {
        for(lli i = 0; i < m; i++) {
            type now = trans[i];
            if(dist[now.start] != -INF && dist[now.end] < dist[now.start] + now.cost) {
                dist[now.end] = dist[now.start] + now.cost;
                if(round >= n-1) dist[now.end] = INF;
            }
        }
        // cout << "\n" << "dist : ";
        // for(int d : dist) cout << d << " ";
    }
    if(dist[e] == INF) return "Gee";
    else if(dist[e] == -INF) return "gg";
    else return to_string(dist[e]);
}

int main() {
    FASTIO
    cout << solve();
}