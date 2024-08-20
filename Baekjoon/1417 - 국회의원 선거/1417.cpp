#include <iostream>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int n, dasom, temp, cnt = 0;
    priority_queue<int> pq;
    
    cin >> n;
    cin >> dasom;

    for(int i = 1; i < n; i++) {
        cin >> temp;
        pq.push(temp);
    }

    while(pq.size() && pq.top() >= dasom) {
        temp = pq.top();
        pq.pop();
        pq.push(temp-1);

        dasom += 1;
        cnt += 1;
    }

    cout << cnt;
}