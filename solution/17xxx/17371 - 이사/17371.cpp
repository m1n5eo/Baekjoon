#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

int cal(pair<int, int> a, pair<int, int> b) {
    return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

pair<int, int> solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> point;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        point.push_back({a, b});
    }

    int dist = INF, idx = -1;
    for(int i = 0; i < n; i++) {
        int now = 0;
        for(int j = 0; j < n; j++) now = max(now, cal(point[i], point[j]));
        if(now < dist) {
            dist = now;
            idx = i;
        }
    }
    return point[idx];
}

int main() {
    FASTIO
    pair<int, int> sol = solve();
    cout << sol.first << " " << sol.second;
}