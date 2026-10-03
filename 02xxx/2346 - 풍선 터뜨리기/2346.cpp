#include <iostream>
#include <deque>
#include <queue>
#include <utility>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, circle;
deque<pair<int, int>> dq;
queue<int> result;

int main() {
    FASTIO
    
    cin >> n;

    for(int i = 0; i < n; i++) {
        int temp;
        cin >> temp;

        dq.push_back({temp, i+1});
    }

    while(dq.size()) {
        if(circle >= 0) {
            for(int i = 0; i < circle-1; i++) {
                dq.push_back(dq.front());
                dq.pop_front();
            }
        }
        else {
            for(int i = 0; i < -circle; i++) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
        }

        circle = dq.front().first;
        result.push(dq.front().second);

        dq.pop_front();
    }

    while(result.size()) {
        cout << result.front() << " ";
        result.pop();
    }
}