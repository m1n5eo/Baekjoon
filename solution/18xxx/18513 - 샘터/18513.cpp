#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

struct compare {
    bool operator()(pair<lli, lli> a, pair<lli, lli> b) {
        if(a.second != b.second) return a.second > b.second;
        else return a.first > b.first;
    }
};

lli solve() {
    lli n, k;
    cin >> n >> k;
    vector<lli> position;
    priority_queue<pair<lli, lli>, vector<pair<lli, lli>>, compare> pq;
    set<lli> visit;
    for(lli i = 0; i < n; i++) {
        lli temp; cin >> temp;
        position.push_back(temp);
        visit.insert(temp);
    }

    sort(position.begin(), position.end());
    for(lli i = 0; i < n; i++) {
        if(visit.find(position[i]-1) == visit.end()) {
            pq.push({position[i]-1, 1});
            visit.insert(position[i]-1);
        }
        if(visit.find(position[i]+1) == visit.end()) {
            pq.push({position[i]+1, 1});
            visit.insert(position[i]+1);
        }
    }

    lli ret = 0;
    for(lli i = 0; i < k; i++) {
        pair<lli, lli> now = pq.top();
        pq.pop();
        ret += now.second;
        if(visit.find(now.first-1) == visit.end()) {
            pq.push({now.first-1, now.second+1});
            visit.insert(now.first-1);
        }
        if(visit.find(now.first+1) == visit.end()) {
            pq.push({now.first+1, now.second+1});
            visit.insert(now.first+1);
        }
    }
    return ret;
}

int main() {
    FASTIO
    cout << solve();
}