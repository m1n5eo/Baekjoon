#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111

int n, w;
vector<pair<int, int>> where(1, {-1, -1});
vector<vector<int>> dp(MAX, vector<int>(MAX, -1));

int distance(int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

int Find(int a, int b) {
    if(a == w || b == w) return 0;
    else if(dp[a][b] != -1) return dp[a][b];

    int next = max(a, b)+1, dist1, dist2;
    if(a == 0) dist1 = distance(1, 1, where[next].first, where[next].second);
    else dist1 = distance(where[a].first, where[a].second, where[next].first, where[next].second);
    if(b == 0) dist2 = distance(n, n, where[next].first, where[next].second);
    else dist2 = distance(where[b].first, where[b].second, where[next].first, where[next].second);

    int result1 = dist1 + Find(next, b);
    int result2 = dist2 + Find(a, next);
    return dp[a][b] = min(result1, result2);
}

void Route(int a, int b) {
    if(a == w || b == w) return;

    int next = max(a, b)+1, dist1, dist2;
    if(a == 0) dist1 = distance(1, 1, where[next].first, where[next].second);
    else dist1 = distance(where[a].first, where[a].second, where[next].first, where[next].second);
    if(b == 0) dist2 = distance(n, n, where[next].first, where[next].second);
    else dist2 = distance(where[b].first, where[b].second, where[next].first, where[next].second);

    if(dp[next][b] + dist1 < dp[a][next] + dist2) {
        cout << 1 << "\n";
        Route(next, b);
    }
    else {
        cout << 2 << "\n";
        Route(a, next);
    }
}

void solve() {
    cin >> n;
    cin >> w;
    for(int i = 1; i <= w; i++) {
        pair<int, int> temp; cin >> temp.first >> temp.second;
        where.push_back(temp);
    }
    cout << Find(0, 0) << "\n";
    Route(0, 0);
}

int main() {
    FASTIO
    solve();
}