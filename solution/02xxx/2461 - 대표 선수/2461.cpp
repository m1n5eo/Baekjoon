#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

struct compare {
    bool operator()(pair<int, int> a, pair<int, int> b) {
        if(a.first != b.first) return a.first > b.first;
        else return a.second > b.second;
    }
};

int solution() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> ability(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> ability[i][j];
        sort(ability[i].begin(), ability[i].end());
    }

    int right = -INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, compare> pq;
    for(int i = 0; i < n; i++) {
        pq.push({ability[i][0], i});
        right = max(right, ability[i][0]);
    }

    int ret = INF;
    vector<int> idx(n, 1);
    while(true) {
        pair<int, int> now = pq.top(); pq.pop();
        ret = min(ret, right-now.first);
        if(idx[now.second] >= m) break;
        pq.push({ability[now.second][idx[now.second]],  now.second});
        right = max(ability[now.second][idx[now.second]], right);
        idx[now.second] += 1;
    }
    return ret;
}

int main() {
    FASTIO
    cout << solution();
}