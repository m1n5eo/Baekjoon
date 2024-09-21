#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define time first
#define complete second

bool compare(pii x, pii y) {
    if(x.complete != y.complete) return x.complete > y.complete;
    else return x.time < y.time;
}

int main() {
    FASTIO

    int n, t, s, now = 0;
    vector<pair<int, int>> v;

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> t >> s;

        v.push_back({t, s});
        now = max(now, s);
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        now -= v[i].time;

        if(i+1 < n && now >= v[i+1].complete) {
            now = v[i+1].complete;
        }
    }

    if(now >= 0) cout << now;
    else cout << -1;
}