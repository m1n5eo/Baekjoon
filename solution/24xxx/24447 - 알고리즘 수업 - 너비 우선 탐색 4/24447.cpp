#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 111111

int n, m, r, visitCnt = 1, visit[MAX], depthCnt = 1, depth[MAX];
vector<int> v[MAX];
queue<int> bfs;

bool compare(int a, int b) {
    return a < b;
}

int main() {
    FASTIO
    
    cin >> n >> m >> r;

    for(int i = 0; i < m; i++) {
        int _v, _e;

        cin >> _v >> _e;

        v[_v].push_back(_e);
        v[_e].push_back(_v);
    }

    for(int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }

    bfs.push(r);
    depth[r] = depthCnt;
    visit[r] = visitCnt++;

    while(bfs.size()) {
        int k = bfs.size();
        depthCnt += 1;

        for(int _ = 0; _ < k; _++) {
            int x = bfs.front();
            int bfs_size = v[x].size();
            
            bfs.pop();

            for(int i = 0; i < bfs_size; i++) {
                if(depth[v[x][i]] == 0) {
                    bfs.push(v[x][i]);
                    depth[v[x][i]] = depthCnt;
                    visit[v[x][i]] = visitCnt++;
                }
            }
        }
    }

    lli result = 0;

    for(int i = 1; i <= n; i++) {
        result += (lli)visit[i]*(lli)(depth[i]-1);
    }

    cout << result;
}