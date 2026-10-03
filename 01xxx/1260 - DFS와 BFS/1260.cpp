#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, m, k, a, b;
vector<vector<bool>> v(MAX, vector<bool>(MAX, 0));
vector<bool> visit(MAX, false);
queue<int> q;

void bfs(int idx) {
    cout << idx << " ";

    q.push(idx);
    visit[idx] = true;
    
    while(1) {
        int num = q.front();
        q.pop();

        for(int i = 1; i <= n; i++){
            if(v[num][i] == true && visit[i] == false) {
                cout << i << " ";

                visit[i] = true;
                q.push(i);
            }
        }

        if(q.size() == 0) {
            break;
        }
    }
}

void dfs(int idx) {
    cout << idx << " ";

    visit[idx] = true;

    for(int i = 1; i <= n; i++) {
        if(v[idx][i] == true && visit[i] == false) {
            dfs(i);
        }
    }
}

int main() {
    FASTIO

    cin >> n >> m >> k;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        v[a][b] = true;
        v[b][a] = true;
    }

    dfs(k);
    cout << "\n";

    for(int i = 0; i <= n; i++) {
        visit[i] = false;
    }

    bfs(k);
}