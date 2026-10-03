#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000
#define MAX 11

int n, min_result = INF, max_result = -INF;
char map[MAX][MAX];

void dfs(int x, int y, int now) {
    if(x == n-1 && y == n-1) {
        min_result = min(min_result, now);
        max_result = max(max_result, now);
    }

    if(x+2 < n) {
        if(map[x+1][y] == '+') dfs(x+2, y, now+(map[x+2][y]-'0'));
        else if(map[x+1][y] == '-') dfs(x+2, y, now-(map[x+2][y]-'0'));
        else if(map[x+1][y] == '*') dfs(x+2, y, now*(map[x+2][y]-'0'));
    }
    if(y+2 < n) {
        if(map[x][y+1] == '+') dfs(x, y+2, now+(map[x][y+2]-'0'));
        else if(map[x][y+1] == '-') dfs(x, y+2, now-(map[x][y+2]-'0'));
        else if(map[x][y+1] == '*') dfs(x, y+2, now*(map[x][y+2]-'0'));
    }
    if(x+1 < n && y+1 < n) {
        if(map[x+1][y] == '+') dfs(x+1, y+1, now+(map[x+1][y+1]-'0'));
        else if(map[x+1][y] == '-') dfs(x+1, y+1, now-(map[x+1][y+1]-'0'));
        else if(map[x+1][y] == '*') dfs(x+1, y+1, now*(map[x+1][y+1]-'0'));

        if(map[x][y+1] == '+') dfs(x+1, y+1, now+(map[x+1][y+1]-'0'));
        else if(map[x][y+1] == '-') dfs(x+1, y+1, now-(map[x+1][y+1]-'0'));
        else if(map[x][y+1] == '*') dfs(x+1, y+1, now*(map[x+1][y+1]-'0'));
    }
}

int main() {
    FASTIO

    cin >> n;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    dfs(0, 0, map[0][0]-'0');
    
    cout << max_result << " " << min_result;
}