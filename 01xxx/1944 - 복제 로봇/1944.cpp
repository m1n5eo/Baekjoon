#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 250*250

struct type {
    int s, e, dist;
};

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<int> parent(MAX);

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

bool isSame(int a, int b) {
    a = Find(a), b = Find(b);
    return a == b;
}

void Union(int a, int b) {
    a = Find(a), b = Find(b);
    if(a < b) parent[b] = a;
    else parent[a] = b;
}

bool compare(type a, type b) {
    return a.dist < b.dist;
}

int solution() {
    int n, m;
    cin >> n >> m;
    vector<string> miro(n);
    vector<pair<int, int>> node;
    for(int i = 0; i < n; i++) {
        cin >> miro[i];
        for(int j = 0; j < n; j++) {
            if(miro[i][j] == 'S' || miro[i][j] == 'K') {
                node.push_back({i, j});
            }
        }
    }

    vector<type> mst;
    int ns = node.size();
    for(int i = 0; i < ns; i++) {
        parent[i] = i;
        for(int j = i+1; j < ns; j++) {
            int d = 0;
            bool breakpoint = true;
            vector<vector<bool>> visited(n, vector<bool>(n, false));
            queue<pair<int, int>> bfs;
            bfs.push(node[i]);
            visited[node[i].first][node[i].second] = true;
            while(!bfs.empty() && breakpoint) {
                int bs = bfs.size(); d += 1;
                for(int _ = 0; _ < bs && breakpoint; _++) {
                    pair<int, int> now = bfs.front(); bfs.pop();
                    for(int k = 0; k < 4 && breakpoint; k++) {
                        pair<int, int> next = {now.first+dx[k], now.second+dy[k]};
                        if(!(0 <= next.first && next.first < n && 0 <= next.second && next.second < n)) continue;
                        else if(miro[next.first][next.second] == '1') continue;
                        else if(visited[next.first][next.second]) continue;
                        else if(node[j] == next) {
                            mst.push_back({i, j, d});
                            breakpoint = false;
                            break;
                        }
                        bfs.push(next);
                        visited[next.first][next.second] = true;
                    }
                }
            }
        }
    }
    sort(mst.begin(), mst.end(), compare);

    int result = 0, k = mst.size();
    for(int i = 0; i < k; i++) {
        if(!isSame(mst[i].s, mst[i].e)) {
            Union(mst[i].s, mst[i].e);
            result += mst[i].dist;
        }
    }
    for(int i = 0; i < ns-1; i++) {
        if(!isSame(i, i+1)) return -1;
    }
    return result;
}

int main() {
    FASTIO
    cout << solution();
}