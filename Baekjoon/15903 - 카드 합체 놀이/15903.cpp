#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n, m;
priority_queue<lli> pq;

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        lli temp;
        cin >> temp;

        pq.push(-temp);
    }

    for(int i = 0; i < m; i++) {
        lli temp = pq.top();
        pq.pop();
        temp += pq.top();
        pq.pop();

        pq.push(temp);
        pq.push(temp);
    }

    lli result = 0;

    for(int i = 0; i < n; i++) {
        result += pq.top();
        pq.pop();
    }

    cout << -result;
}