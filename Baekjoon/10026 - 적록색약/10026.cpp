#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int n, result[2];
vector<vector<vector<int>>> map(MAX, vector<vector<int>>(MAX, vector<int>(2, 0)));
vector<vector<vector<bool>>> check(MAX, vector<vector<bool>>(MAX, vector<bool>(2, false)));

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y, int type) {
    check[x][y][type] = true;

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
            if(map[nx][ny][type] == map[x][y][type] && check[nx][ny][type] == false) {
                dfs(nx, ny, type);
            }
        }
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        string temp;
        cin >> temp;
        
        for(int j = 0; j < n; j++) {
            if(temp[j] == 'R') {
                map[i][j][0] = 1;
                map[i][j][1] = 1;
            }
            else if(temp[j] == 'G') {
                map[i][j][0] = 2;
                map[i][j][1] = 1;
            }
            else if(temp[j] == 'B') {
                map[i][j][0] = 3;
                map[i][j][1] = 3;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < 2; k++) {
                if(check[i][j][k] == false) {
                    dfs(i, j, k);
                    result[k] += 1;
                }
            }
        }
    }

    cout << result[0] << " " << result[1];
}