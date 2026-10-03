#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int
#define INF 2147483647

int n, k;
vector<int> v;
priority_queue<pair<int, int>> pq;

int main() {
    FASTIO

    cin >> n >> k;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        
        v.push_back(temp);
        pq.push({-temp, i});
    }

    int idx = 1;

    while(idx < k) {
        for(int i = pq.top().second; i < n; i++) {
            if(-(lli)pq.top().first*(lli)v[i] <= INF) pq.push({pq.top().first*v[i], i});
        }
        pq.pop();
        idx += 1;
    }

    cout << -pq.top().first;
}