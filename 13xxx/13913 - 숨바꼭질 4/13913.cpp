#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 222222

int main() {
    FASTIO

    int n, k;

    cin >> n >> k;

    if(n == k) {
        cout << 0 << "\n";
        cout << n;
        exit(0);
    }

    int cnt = 0;
    vector<int> check(MAX, -1);
    queue<int> bfs;
    bfs.push(n);

    while(bfs.size()) {
        int bfs_size = bfs.size();
        cnt += 1;

        for(int _ = 0; _ < bfs_size; _++) {
            int now = bfs.front();
            bfs.pop();

            if(now-1 >= 0 && check[now-1] == -1) {
                check[now-1] = now;
                bfs.push(now-1);
            }
            if(now+1 <= 100000 && check[now+1] == -1) {
                check[now+1] = now;
                bfs.push(now+1);
            }
            if(now*2 <= 100000 && check[now*2] == -1) {
                check[now*2] = now;
                bfs.push(now*2);
            }
        }

        if(check[k] != -1) break;
    }

    vector<int> result = {k};

    while(n != k) {
        k = check[k];
        result.push_back(k);
    }

    cout << cnt << "\n";

    for(int i = cnt; i >= 0; i--) {
        cout << result[i] << " ";
    }
}