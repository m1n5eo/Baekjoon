#include <bits/stdc++.h>
using namespace std;

int n, x, y, cnt, pan[101][101];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);

    cin >> n;
    for(int k = 0; k < n; k++) {
        cin >> x >> y;
        for(int i = x; i < x+10; i++) {
            for(int j = y; j < y+10; j++) {
                pan[i][j] = 1;
            }
        }
    }
    for(int i = 1; i <= 100; i++) {
        for(int j = 1; j <= 100; j++) {
            if(pan[i][j] == 1) {
                for(int k = 0; k < 4; k++) {
                    int tempX = i+dx[k], tempY = j+dy[k];
                    if(pan[tempX][tempY] == 0) cnt++;
                }
            }
        }
    }
    cout << cnt;
}