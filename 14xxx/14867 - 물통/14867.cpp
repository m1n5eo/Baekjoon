#include <iostream>
#include <utility>
#include <queue>
#include <map>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>

int main() {
    FASTIO

    pii capacity, after;
    queue<pii> bfs;
    map<pii, bool> m;
    int cnt = 0;
    bool stop_point = true;

    cin >> capacity.first >> capacity.second >> after.first >> after.second;

    if(after == make_pair(0, 0)) {
        cout << 0;
        exit(0);
    }

    bfs.push({0, 0});
    m.insert({{0, 0}, true});

    while(bfs.size() && stop_point) {
        int n = bfs.size();
        cnt += 1;

        for(int _ = 0; _ < n && stop_point; _++) {
            pii now = {bfs.front().first, bfs.front().second}, next;
            bfs.pop();

            next = {capacity.first, now.second};
            if(after == next) stop_point = false;
            else if(m.find(next) == m.end()) {
                m.insert({next, true});
                bfs.push({next});
            }

            next = {now.first, capacity.second};
            if(after == next) stop_point = false;
            else if(m.find(next) == m.end()) {
                m.insert({next, true});
                bfs.push({next});
            }

            next = {0, now.second};
            if(after == next) stop_point = false;
            else if(m.find(next) == m.end()) {
                m.insert({next, true});
                bfs.push({next});
            }

            next = {now.first, 0};
            if(after == next) stop_point = false;
            else if(m.find(next) == m.end()) {
                m.insert({next, true});
                bfs.push({next});
            }

            if(capacity.second-now.second >= now.first) next = {0, now.first+now.second};
            else next = {now.first-(capacity.second-now.second), capacity.second};
            if(after == next) stop_point = false;
            else if(m.find(next) == m.end()) {
                m.insert({next, true});
                bfs.push({next});
            }
            
            if(capacity.first-now.first >= now.second) next = {now.first+now.second, 0};
            else next = {capacity.first, now.second-(capacity.first-now.first)};
            if(after == next) stop_point = false;
            else if(m.find(next) == m.end()) {
                m.insert({next, true});
                bfs.push({next});
            }
        }
    }

    if(stop_point == false) cout << cnt;
    else cout << -1;
}