#include <bits/stdc++.h>
using namespace std;

int n, cnt = 0;
char rgbPan[111][111], savePan[111][111];

void clearPan() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            rgbPan[i][j] = savePan[i][j];
        }
    }
}

void rgbDfs(int x, int y, char rgb) {
    if(x < 0 || x >= n || y < 0 || y >= n) return;
    else if(rgbPan[x][y] != rgb || rgbPan[x][y] == 0) return;
    rgbPan[x][y] = 0;
    rgbDfs(x-1, y, rgb);
    rgbDfs(x+1, y, rgb);
    rgbDfs(x, y-1, rgb);
    rgbDfs(x, y+1, rgb);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf(" %c", &rgbPan[i][j]);
            if(rgbPan[i][j] == 'G') savePan[i][j] = 'R';
            else savePan[i][j] = rgbPan[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(rgbPan[i][j]) {
                rgbDfs(i, j, rgbPan[i][j]);
                cnt++;
            }
        }
    }
    printf("%d ", cnt);
    clearPan(); cnt = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(rgbPan[i][j]) {
                rgbDfs(i, j, rgbPan[i][j]);
                cnt++;
            }
        }
    }
    printf("%d", cnt);
}
