#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222222

int sec[222222], chk[222222], cnt[222222];

int main() {
    int n, k;

    cin >> n >> k;

    vector<int> sec(MAX, 0), cnt(MAX, 0);
    vector<bool> check(MAX, false);
    queue<int> bfs;

    check[n] = true;
    sec[n] = 0;
    cnt[n] = 1;
    bfs.push(n);

    while(bfs.size()) {
        int now = bfs.front();
        bfs.pop();

        vector<int> next = {now-1, now+1, now*2};

        for(int k = 0; k < 3; k++) {
            if(0 <= next[k] && next[k] <= 100000) {
                if(check[next[k]] == false) {
                    check[next[k]] = true;
                    sec[next[k]] = sec[now]+1;
                    cnt[next[k]] = cnt[now];
                    bfs.push(next[k]);
                }
                else if(sec[next[k]] == sec[now]+1) {
                    cnt[next[k]] += cnt[now];
                }
            }
        }
    }

    cout << sec[k] << "\n" << cnt[k];
}