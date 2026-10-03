#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

int n, m;
int pan[111][111], dist[111][111];
bool visited[111][111];
queue<pair<int, int>> q;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for(int j = 0; j < m; j++) {
            pan[i][j] = str[j]-'0';
        }
    }

    q.push({0, 0});
    visited[0][0] = true;
    dist[0][0] = 1;

    while(q.size()) {
        int x = q.front().first, y = q.front().second;
        q.pop();

        if(x > 0 && pan[x-1][y] == 1 && visited[x-1][y] == false) {
            dist[x-1][y] = dist[x][y]+1;
            visited[x-1][y] = true;
            q.push({x-1, y});
        }
        if(x < n-1 && pan[x+1][y] == 1 && visited[x+1][y] == false) {
            dist[x+1][y] = dist[x][y]+1;
            visited[x+1][y] = true;
            q.push({x+1, y});
        }
        if(y > 0 && pan[x][y-1] == 1 && visited[x][y-1] == false) {
            dist[x][y-1] = dist[x][y]+1;
            visited[x][y-1] = true;
            q.push({x, y-1});
        }
        if(y < m-1 && pan[x][y+1] == 1 && visited[x][y+1] == false) {
            dist[x][y+1] = dist[x][y]+1;
            visited[x][y+1] = true;
            q.push({x, y+1});
        }
    }

    cout << dist[n-1][m-1];

    return 0;
}