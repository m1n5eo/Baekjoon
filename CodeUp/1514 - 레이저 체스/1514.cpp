#include <bits/stdc++.h>
using namespace std;

int ChessMap[11][11], check[11][11];

void RazerPoint(int x, int y) {
    check[x][y] = 1;
    for(int i = 1; i <= 7; i++) {
        if(ChessMap[x][i] == 2 && !check[x][i]) RazerPoint(x, i);
        else if(!ChessMap[x][i]) ChessMap[x][i] = 1;
        if(ChessMap[i][y] == 2 && !check[i][y]) RazerPoint(i, y);
        else if(!ChessMap[i][y]) ChessMap[i][y] = 1;
    }
    return;
}

int main() {
    int n, m;
    for(int i = 1; i <= 7; i++) ChessMap[4][i] = 1;
    for(int i = 0; i < 3; i++) {
        scanf("%d %d", &n, &m);
        if(ChessMap[n][m]) RazerPoint(n, m);
        ChessMap[n][m] = 2;
    }
    for(int i = 1; i <= 7; i++) {
        for(int j = 1; j <= 7; j++) {
            printf("%d ", ChessMap[i][j]);
        }
        printf("\n");
    }
}