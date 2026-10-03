#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int solve() {
    int n, m, temp;
    cin >> n >> m;
    vector<pair<int, int>> trash;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> temp;
            if(temp == 1) trash.push_back({i, j});
        }
    }

    int k = trash.size();
    vector<pair<int, int>> now;
    now.push_back(trash[0]);
    for(int i = 1; i < k; i++) {
        int ns = now.size();
        for(int j = 0; j < ns; j++) {
            if(now[j].first <= trash[i].first && now[j].second <= trash[i].second) {
                now[j] = trash[i];
                break;
            }
            else if(j == ns-1) now.push_back(trash[i]);
        }
    }
    return now.size();
}

int main() {
    FASTIO
    cout << solve();
}