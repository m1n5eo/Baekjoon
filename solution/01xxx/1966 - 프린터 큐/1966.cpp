#include <bits/stdc++.h>
using namespace std;

int n, m, t, temp, cnt = 0;
queue<pair<int,int>> q;
priority_queue<int> pq;

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> t;
    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) {
            cin >> temp;
            pq.push(temp);
            q.push({temp, i});
        }
        while(q.size()) {
            int num = q.front().first, idx = q.front().second;
            q.pop();
            if(pq.top() == num) {
                pq.pop();
                if(idx == m) {
                    cout << n-pq.size() << "\n";
                    break;
                }
            }
            else q.push({num, idx});
        }
        while(pq.size()) {pq.pop(); q.pop();}
    }
}