#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp, idx, cnt = 0;
    deque<int> dq;

    cin >> n >> m;
    for(int i = 1; i <= n; i++) dq.push_back(i);
    while(m--) {
        cin >> temp;
        for(int i = 0; i < dq.size(); i++) {
            if(dq[i] == temp) {
                idx = i;
                break;
            }
        }
        int k = dq.size()-idx;
        if(idx < k) {
            while(1) {
                if(dq.front() == temp) {
                    dq.pop_front();
                    break;
                }
                dq.push_back(dq.front());
                dq.pop_front();
                cnt++;
            }
        }
        else {
            while(1) {
                if(dq.front() == temp) {
                    dq.pop_front();
                    break;
                }
                dq.push_front(dq.back());
                dq.pop_back();
                cnt++;
            }
        }
    }
    cout << cnt;
}