#include <iostream>
#include <string>
using namespace std;

int n, m, start_x, start_y;
int map[2222][2222];
string str;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if(!(0 <= x && x < n && 0 <= y && y < m)) return;
    else if(map[x][y] == -1) return;
    else if(map[x][y] == 1) return;

    map[x][y] = 1;

    if((x == 0 || x == n-1 || y == 0 || y == m-1) && !(x == start_x && y == start_y)) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(map[i][j] == -1) cout << '+';
                else if(map[i][j] == 0) cout << '@';
                else if(map[i][j] == 1) cout << '.';
            }
            cout << "\n";
        }

        exit(0);
    }

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        dfs(nx, ny);
    }

    map[x][y] = 0;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == '+') map[i][j] = -1;
            else if(str[j] == '.') {
                map[i][j] = 0;
                
                if(i == 0 || i == n-1 || j == 0 || j == m-1) {
                    start_x = i;
                    start_y = j;
                }
            }
        }
    }

    dfs(start_x, start_y);
}