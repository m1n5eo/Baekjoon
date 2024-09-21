#include <iostream>
#include <queue>
using namespace std;

int t, n, paper;
long long int sum;
priority_queue<long long int> pq;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> paper;
            pq.push(-paper);
        }

        while(pq.size() > 1) {
            long long int temp1 = pq.top();
            pq.pop();
            long long int temp2 = temp1+pq.top();
            pq.pop();
            sum += temp2;
            pq.push(temp2);
        }

        cout << -sum << "\n";

        while(pq.size()) pq.pop();
        sum = 0;
    }

    return 0;
}