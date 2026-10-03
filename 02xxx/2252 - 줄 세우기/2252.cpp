#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, m, a, b;

    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>(0));
    vector<int> cnt(n+1, 0), result;
    vector<bool> check(n+1, 0);
    queue<int> q;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;

        graph[a].push_back(b);
        cnt[b] += 1;
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) q.push(i);
    }

    for(int i = 1; i <= n; i++) {
        int x = q.front();
        q.pop();

        result.push_back(x);

        int graph_size = graph[x].size();

        for(int i = 0; i < graph_size; i++) {
            int next = graph[x][i];

            if(cnt[next] == 0) continue;
            else if(cnt[next]-1 == 0) {
                cnt[next] -= 1;
                q.push(next);
            }
            else cnt[next] -= 1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}