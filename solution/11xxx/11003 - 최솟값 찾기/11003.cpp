#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, k, temp;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> temp;

        pq.push({temp, i});

        while(pq.size()) {
            if(i-k < pq.top().second && pq.top().second <= i) {
                cout << pq.top().first << " ";
                break;
            }
            else {
                pq.pop();
            }
        }
    }

    return 0;
}