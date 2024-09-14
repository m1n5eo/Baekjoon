#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, m, a, b;

    cin >> n >> m;

    vector<vector<int>> problem(n+1, vector<int>(0));
    vector<int> cnt(n+1, 0), result;
    priority_queue<int, vector<int>, greater<int>> pq;

    for(int _ = 0; _ < m; _++) {
        cin >> a >> b;
        
        problem[a].push_back(b);
        cnt[b] += 1;
    }

    for(int i = 1; i <= n; i++) {
        if(cnt[i] == 0) pq.push(i);
    }

    for(int _ = 0; _ < n; _++) {
        int x = pq.top();
        pq.pop();

        result.push_back(x);

        for(int next : problem[x]) {
            if(cnt[next] == 0) continue;
            else if(cnt[next]-1 == 0) {
                cnt[next] -= 1;
                pq.push(next);
            }
            else {
                cnt[next] -= 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
}