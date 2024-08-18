#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 1111111

int main() {
    FASTIO

    int a, b, cnt = 0;
    vector<bool> visit(MAX, false);
    queue<int> bfs;

    cin >> a >> b;

    bfs.push(a);
    visit[a] = true;

    while(bfs.size()) {
        int bfs_size = bfs.size();
        cnt += 1;

        for(int i = 0; i < bfs_size; i++) {
            int x = bfs.front();

            bfs.pop();

            if(x+1 < b && visit[x+1] == false) {
                bfs.push(x+1);
                visit[x+1] = true;
            }
            else if(x+1 == b) {
                cout << cnt << " ";
                return 0;
            }

            if(x*2 < b && visit[x*2] == false) {
                bfs.push(x*2);
                visit[x*2] = true;
            }
            else if(x*2 == b) {
                cout << cnt << " ";
                return 0;
            }
        }
    }
}