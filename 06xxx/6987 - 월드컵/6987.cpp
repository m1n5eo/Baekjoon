#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int ret = 0;
vector<vector<int>> vec(6, vector<int>(3, 0));

void backtracking(int x, int y, int cnt) {
    if(cnt == 0) {
        ret = 1;
        return;
    }

    if(vec[x][0] != 0 && vec[y][2] != 0) {
        vec[x][0] -= 1; vec[y][2] -= 1;
        backtracking(y != 5? x:x+1, y != 5? y+1:x+2, cnt-1);
        vec[x][0] += 1; vec[y][2] += 1;
    }
    if(vec[x][1] != 0 && vec[y][1] != 0) {
        vec[x][1] -= 1; vec[y][1] -= 1;
        backtracking(y != 5? x:x+1, y != 5? y+1:x+2, cnt-1);
        vec[x][1] += 1; vec[y][1] += 1;
    }
    if(vec[x][2] != 0 && vec[y][0] != 0) {
        vec[x][2] -= 1; vec[y][0] -= 1;
        backtracking(y != 5? x:x+1, y != 5? y+1:x+2, cnt-1);
        vec[x][2] += 1; vec[y][0] += 1;
    }
}

int solve() {
    int win = 0, draw = 0, defeat = 0; ret = 0;
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 3; j++) {
            cin >> vec[i][j];
            if(j == 0) win += vec[i][j];
            else if(j == 1) draw += vec[i][j];
            else if(j == 2) defeat += vec[i][j];
        }
    }

    if(draw%2 == 1) return 0;
    else if(win+draw/2 != 15) return 0;
    else if(draw/2+defeat != 15) return 0; 
    else if(win != defeat) return 0;
    
    backtracking(0, 1, 15);
    return ret;
}

int main() {
    FASTIO
    int tc = 4;
    while(tc--) cout << solve() << " ";
}