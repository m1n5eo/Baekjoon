#include <bits/stdc++.h>
using namespace std;

int n, m, r, c, d, cnt = 0, arr[55][55];
int leftx[4] = {0, -1, 0, 1}, backx[4] = {1, 0, -1, 0};
int lefty[4] = {-1, 0, 1, 0}, backy[4] = {0, -1, 0, 1};

void moveRobot(int x, int y, int dis) {
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    else if(arr[x+backx[dis]][y+backy[dis]] == 1 && arr[x-1][y] && arr[x+1][y] && arr[x][y-1] && arr[x][y+1]) return;
    if(arr[x][y] == 0) cnt++;
    arr[x][y] = 2;
    if(arr[x-1][y] && arr[x+1][y] && arr[x][y-1] && arr[x][y+1]) moveRobot(x+backx[dis], y+backy[dis], dis);
    else if(arr[x+leftx[dis]][y+lefty[dis]]) moveRobot(x, y, (dis+3)%4);
    else if(!arr[x+leftx[dis]][y+lefty[dis]]) moveRobot(x+leftx[dis], y+lefty[dis], (dis+3)%4);
}

int main() {
    cin >> n >> m;
    cin >> r >> c >> d; // 0위쪽 1오른쪽 2아래쪽 3왼쪽
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    moveRobot(r, c, d);
    if(!cnt) cnt++;
    cout << cnt;
}