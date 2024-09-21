#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    FASTIO

    int n;
    deque<int> dq;
    vector<pair<int, int>> v;

    cin >> n;

    for(int i = 1; i <= n; i++) {
        dq.push_back(i);
    }

    for(int i = 1; i <= n; i++) {
        for(int j = 0; j < i; j++) {
            dq.push_back(dq.front());
            dq.pop_front();
        }

        v.push_back({dq.front(), i});
        dq.pop_front();
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < n; i++) {
        cout << v[i].second << " ";
    }
}