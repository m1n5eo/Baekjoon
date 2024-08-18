#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define MAX 111111

int n, m, r, k, cnt = 1, visit[MAX], depth[MAX];
vector<int> v[MAX];

bool compare(int a, int b) {
    return a > b;
}

void dfs(int x, int d) {
    int v_size = v[x].size();

    for(int i = 0; i < v_size; i++) {
        if(visit[v[x][i]] == 0) {
            visit[v[x][i]] = cnt++;
            depth[v[x][i]] = d;
            dfs(v[x][i], d+1);
        }
    }
}

int main() {
    FASTIO

    cin >> n >> m >> r;

    for(int i = 1; i <= n; i++) depth[i] = -1;

    for(int _ = 0; _ < m; _++) {
        int _v, _e;

        cin >> _v >> _e;

        v[_v].push_back(_e);
        v[_e].push_back(_v);
    }

    for(int i = 1; i <= n; i++) {
        sort(v[i].begin(), v[i].end(), compare);
    }

    visit[r] = cnt++;
    depth[r] = 0;
    dfs(r, 1);
    
    lli result = 0;

    for(int i = 1; i <= n; i++) {
        result += (lli)visit[i]*(lli)depth[i];
    }

    cout << result;
}