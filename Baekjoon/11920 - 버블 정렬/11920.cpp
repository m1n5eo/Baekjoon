#include <iostream>
#include <queue>
using namespace std;

int n, k, arr[111111];
priority_queue<int> pq;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for(int i = 0; i < k; i++) {
        pq.push(-arr[i]);
    }

    for(int i = k; i < n; i++) {
        if(-pq.top() < arr[i]) {
            int temp = arr[i];
            arr[i] = -pq.top();
            pq.pop();
            pq.push(-temp);
        }
    }

    for(int i = k; i < n; i++) {
        cout << arr[i] << " ";
    }
    while(pq.size()) {
        cout << -pq.top() << " ";
        pq.pop();
    }

    return 0;
}