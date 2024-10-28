#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111111

struct type {
    int id, time, priority;
};

struct compare {
    bool operator() (type &x, type &y) {
        if(x.priority != y.priority) return x.priority < y.priority;
        else return x.id > y.id;
    }
};

int main() {
    FASTIO

    int t, n, a, b, c;
    priority_queue<type, vector<type>, compare> pq;

    cin >> t >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> a >> b >> c;
        pq.push({a, b, c});
    }

    for(int _ = 0; _ < t && pq.size(); _++) {
        type now = pq.top();
        pq.pop();

        cout << now.id << " ";

        now.priority -= 1;
        now.time -= 1;

        if(now.time != 0) {
            pq.push(now);
        }
    }
}