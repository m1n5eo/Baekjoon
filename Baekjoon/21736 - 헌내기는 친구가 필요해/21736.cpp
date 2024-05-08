#include <iostream>
#include <queue>
#include <utility>
#include <string>
using namespace std;

#define fi first
#define se second

int n, m, cnt, map[666][666];
bool visited[666][666];
string str[666];
queue<pair<int, int>> q;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str[i];
        for(int j = 0; j < m; j++) {
            if(str[i][j] == 'O') map[i][j] = 0;
            else if(str[i][j] == 'X') map[i][j] = 9;
            else if(str[i][j] == 'P') map[i][j] = 1;
            else if(str[i][j] == 'I') {
                q.push({i, j});
                visited[i][j] = true;
            }
        }
    }
    
    while(q.size()) {
        int x = q.front().fi, y = q.front().se;
        q.pop();

        for(int k = 0; k < 4; k++) {
            int nx = x+dx[k], ny = y+dy[k];

            if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                if(map[nx][ny] == 0 && visited[nx][ny] == false) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
                else if(map[nx][ny] == 1 && visited[nx][ny] == false) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    cnt += 1;
                }
            }
        }
    }

    if(cnt == 0) cout << "TT";
    else cout << cnt;

    return 0;
}