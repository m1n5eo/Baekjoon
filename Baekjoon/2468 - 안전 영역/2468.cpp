#include <bits/stdc++.h>
using namespace std;

int n, cntMax = -1234567890, heightMax = -1234567890;
int height[101][101], heightCopy[101][101]; // 0.침범안함 1.침범 2.숫자샐때

void dfs(int a, int b) {
    if(a < 0 || b < 0 || a >= n || b >= n) return;
    if(height[a][b] == 1 || height[a][b] == 2) return;
    height[a][b] = 2;
    dfs(a-1, b);
    dfs(a+1, b);
    dfs(a, b-1);
    dfs(a, b+1);
}

void copy() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            height[i][j] = heightCopy[i][j];
        }
    }
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &height[i][j]);
            heightCopy[i][j] = height[i][j];
            heightMax = max(height[i][j], heightMax);
        }
    }
    for(int t = 0; t <= heightMax; t++) {
        int cnt = 0;
        copy();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(height[i][j] > t) height[i][j] = 0;
                else height[i][j] = 1;
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(height[i][j] == 0) {
                    cnt++;
                    dfs(i, j);
                }
            }
        }
        cntMax = max(cnt, cntMax);
    }
    printf("%d", cntMax);
}
