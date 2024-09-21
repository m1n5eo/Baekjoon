#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 55

int n, m;
bool result = false;
string temp;
vector<vector<int>> map(MAX, vector<int>(MAX, 0));
vector<vector<bool>> visit(MAX, vector<bool>(MAX, false));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int bx, int by) {
    visit[x][y] = true;

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
            if(map[x][y] == map[nx][ny] && visit[nx][ny] == true && !(nx == bx && ny == by)) {
                result = true;
                return;
            }
            else if(map[x][y] == map[nx][ny] && visit[nx][ny] == false && !(nx == bx && ny == by)) {
                dfs(nx, ny, x, y);
            }
        }
    }
}

int main() {
    FASTIO
    
    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        cin >> temp;

        for(int j = 0; j < m; j++) {
            map[i][j] = temp[j]-'A';
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visit[i][j] == false) {
                dfs(i, j, -1, -1);
            }
        }
    }

    if(result == true) cout << "Yes";
    else cout << "No";
}