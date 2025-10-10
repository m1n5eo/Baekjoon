#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>

bool compare(pii x, pii y) {
    if(x.second != y.second) return x.second > y.second;
    else return x.first < y.first;
}

int solve() {
    int n, now = 0;
    cin >> n;
    vector<pair<int, int>> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        now = max(now, v[i].second);
    }

    sort(v.begin(), v.end(), compare);
    for(int i = 0; i < n; i++) {
        now -= v[i].first;
        if(i+1 < n && now >= v[i+1].second) now = v[i+1].second;
    }
    
    if(now >= 0) return now;
    else return -1;
}

int main() {
    FASTIO
    cout << solve();
}