#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool reversed(int a, int b) {
    return a > b;
}

int solve() {
    int n, m;
    cin >> n >> m;
    vector<int> time;
    for(int i = 0; i < n; i++) {
        int temp; cin >> temp;
        time.push_back(temp);
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    sort(time.begin(), time.end(), reversed);
    for(int i = 0; i < m; i++) pq.push(0);
    for(int t : time) {
        int k = pq.top(); pq.pop();
        pq.push(t+k);
    }
    
    int ret = 0;
    while(!pq.empty()) {
        ret = max(ret, pq.top());
        pq.pop();
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}