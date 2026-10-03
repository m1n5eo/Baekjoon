#include <bits/stdc++.h>
using namespace std;

int pan[11][11], iCheck[11][11], jCheck[11][11], Check33[11][11];

void backtracking(int x, int y) {
    if(x == 10 && y == 1) {
        for(int i = 1; i <= 9; i++) {
            for(int j = 1; j <= 9; j++) {
                cout << pan[i][j];
            }
            cout << "\n";
        }
        exit(0);
    }
    if(pan[x][y]) {
        if(y == 9) backtracking(x+1, 1);
        else backtracking(x, y+1);
    }
    else {
        for(int i = 1; i <= 9; i++) {
            if(iCheck[x][i] && jCheck[y][i] && Check33[(x-1)/3*3+(y-1)/3+1][i]) {
                pan[x][y] = i;
                iCheck[x][i] = 0;
                jCheck[y][i] = 0;
                Check33[(x-1)/3*3+(y-1)/3+1][i] = 0;
                if(y == 9) backtracking(x+1, 1);
                else backtracking(x, y+1);
                pan[x][y] = 0;
                iCheck[x][i] = 1;
                jCheck[y][i] = 1;
                Check33[(x-1)/3*3+(y-1)/3+1][i] = 1;
            }
        }
    }
}

void setting() {
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            iCheck[i][j] = 1;
            jCheck[i][j] = 1;
            Check33[i][j] = 1;
        }
    }
}

int main() {
    cin.tie(NULL);
    cin.sync_with_stdio(false);
    setting();
    for(int i = 1; i <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            scanf("%1d", &pan[i][j]);
            if(pan[i][j] != 0) {
                iCheck[i][pan[i][j]] = 0;
                jCheck[j][pan[i][j]] = 0;
                Check33[((i-1)/3*3)+((j-1)/3)+1][pan[i][j]] = 0;
            }
        }
    }
    backtracking(1, 1);
}