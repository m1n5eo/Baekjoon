#include <iostream>
#include <deque>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int n, k, cnt = 0;
deque<int> dq;

void backtracking(int sum) {
    if(sum == n) {
        cnt += 1;

        if(cnt == k) {
            int dq_size = dq.size();

            for(int i = 0; i < dq_size; i++) {
                cout << dq.front();
                dq.pop_front();

                if(i != dq_size-1) cout << "+";
            }

            exit(0);
        }
    }
    else if(sum > n) return;

    for(int i = 1; i <= 3; i++) {
        dq.push_back(i);
        backtracking(sum+i);
        dq.pop_back();
    }
}

int main() {
    FASTIO
    
    cin >> n >> k;

    backtracking(0);

    cout << -1;
}