#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    priority_queue<int> pq;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> k;
        pq.push(k);
    }

    while(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}