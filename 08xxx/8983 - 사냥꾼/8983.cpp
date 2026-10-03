#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 123456789000

bool compare(pair<lli, lli> a, pair<lli, lli> b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

lli dist(pair<lli, lli> a, pair<lli, lli> b) {
    return abs(a.first-b.first) + abs(a.second-b.second);
}

lli solve() {
    lli n, m, l;
    cin >> m >> n >> l;
    vector<pair<lli, lli>> gun, animal;
    for(lli i = 0; i < m; i++) {
        lli temp; cin >> temp;
        gun.push_back({temp, 0});
    }
    for(lli i = 0; i < n; i++) {
        lli x, y; cin >> x >> y;
        animal.push_back({x, y});
    }

    gun.push_back({INF, 0});
    sort(gun.begin(), gun.end(), compare);
    sort(animal.begin(), animal.end(), compare);
    lli now = 0, ret = 0;
    for(lli i = 0; i < n; i++) {
        while(now+1 < m && gun[now+1].first < animal[i].first) now += 1;
        if(dist(gun[now], animal[i]) <= l) ret += 1;
        else if(now+1 < m && dist(gun[now+1], animal[i]) <= l) ret += 1;
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}