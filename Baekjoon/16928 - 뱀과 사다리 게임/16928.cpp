#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int n, m, a, b;
int mv[111], dist[111];
queue<int> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n+m; i++) {
        cin >> a >> b;
        mv[a] = b;
    }

    q.push(1);

    while(q.size()) {
        int init = q.front();
        q.pop();

        if(init == 100) {
            cout << dist[100];
            break;
        }

        for(int k = 1; k <= 6; k++) {
            int dice = init+k;

            if(mv[dice] == 0 && dist[dice] == 0) {
                q.push(dice);
                dist[dice] = dist[init]+1;
            }
            else if(mv[dice]) {
                int idx = dice;

                while(mv[idx] != 0) idx = mv[dice];

                if(dist[idx] == 0) {
                    q.push(idx);
                    dist[idx] = dist[init]+1;
                }
            }
        }
    }

    return 0;
}