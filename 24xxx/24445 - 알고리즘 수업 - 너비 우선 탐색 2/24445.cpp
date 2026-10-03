#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

int n, m, r, cnt = 1, result[MAX];
vector<int> v[MAX];
queue<int> bfs;

bool compare(int a, int b) {
    return a > b;
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
    result[r] = cnt++;

    while(bfs.size()) {
        int x = bfs.front();
        int bfs_size = v[x].size();
        
        bfs.pop();

        for(int i = 0; i < bfs_size; i++) {
            if(result[v[x][i]] == 0) {
                bfs.push(v[x][i]);
                result[v[x][i]] = cnt++;
            }
        }
    }

    for(int i = 1; i <= n; i++) {
        cout << result[i] << " ";
    }
}