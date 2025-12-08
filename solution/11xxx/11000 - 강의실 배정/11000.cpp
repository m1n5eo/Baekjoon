#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

bool compare(pair<int, int> a, pair<int, int> b) {
    if(a.first != b.first) return a.first < b.first;
    else return a.second < b.second;
}

int solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> clock;
    for(int i = 0; i < n; i++) {
        int a, b; cin >> a >> b;
        clock.push_back({a, b});
    }

    priority_queue<int, vector<int>, cmp> pq;
    sort(clock.begin(), clock.end(), compare);
    for(pair<int, int> c : clock) {
        if(!(pq.empty() || pq.top() > c.first)) pq.pop();
        pq.push(c.second);
    }
    return pq.size();
}

int main() {
    FASTIO
    cout << solve();
}