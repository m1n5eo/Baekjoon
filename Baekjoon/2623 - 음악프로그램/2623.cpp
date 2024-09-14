#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, m;
    
    cin >> n >> m;

    vector<vector<int>> graph(n+1, vector<int>(0));
    vector<int> cnt(n+1, 0), result;
    queue<int> q;

    for(int _ = 0; _ < m; _++) {
        int k, temp, before;

        cin >> k;
        
        for(int i = 0; i < k; i++) {
            cin >> temp;

            if(i != 0) {
                graph[before].push_back(temp);
                cnt[temp] += 1;
            }

            before = temp;
        }
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) {
            q.push(i);
        }
    }

    for(int _ = 0; _ < n; _++) {
        if(!q.size()) {
            cout << 0;
            exit(0);
        }

        int x = q.front();
        q.pop();

        result.push_back(x);

        for(int next : graph[x]) {
            if(cnt[next] == 0) continue;
            else if(cnt[next]-1 == 0) {
                cnt[next] -= 1;
                q.push(next);
            }
            else cnt[next] -= 1;
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }
}