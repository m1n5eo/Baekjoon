#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

pair<int, int> sol = {0, 0};
vector<vector<vector<int>>> gamepan(2, vector<vector<int>>(10, vector<int>(4, 0)));

void remove_ban_line(int k) {
    vector<int> check(2, 0);
    for(int i = 4; i <= 5; i++) {
        for(int j = 0; j < 4; j++) {
            if(gamepan[k][i][j] == 1) {
                check[i-4] = 1;
            }
        }
    }

    int cnt = check[0] + check[1];
    for(int i = 9; i >= 6; i--) gamepan[k][i] = gamepan[k][i-cnt];
    for(int i = 4; i <= 5; i++) gamepan[k][i] = {0, 0, 0, 0};
}

void push_line(int k) {
    vector<vector<int>> save;
    for(int i = 9; i >= 0; i--) {
        if(gamepan[k][i][0] + gamepan[k][i][1] + gamepan[k][i][2] + gamepan[k][i][3] != 0) {
            save.push_back(gamepan[k][i]);
        }
    }

    int idx = 9;
    gamepan[k] = vector<vector<int>>(10, vector<int>(4, 0));
    for(vector<int> s : save) {
        gamepan[k][idx] = s;
        idx -= 1;
    }
}

void remove_full_line(int k) {
    for(int i = 9; i >= 0; i--) {
        int cnt = 0;
        for(int j = 0; j < 4; j++) {
            if(gamepan[k][i][j] == 1) {
                cnt += 1;
            }
        }
        if(cnt == 4) {
            sol.first += 1;
            for(int j = 0; j < 4; j++) {
                gamepan[k][i][j] = 0;
            }
        }
    }
}

void place(int t, int x, int y, int k) {
    if(t == 1) {
        int xx = 0;
        while(xx < 10 && gamepan[k][xx][y] == 0) xx += 1;
        xx -= 1;
        gamepan[k][xx][y] = 1;
    }
    else if(t == 2) {
        int xx = 0;
        while(xx < 10 && gamepan[k][xx][y] == 0 && gamepan[k][xx][y+1] == 0) xx += 1;
        xx -= 1;
        gamepan[k][xx][y] = 1;
        gamepan[k][xx][y+1] = 1;
    }
    else if(t == 3) {
        int xx = 0;
        while(xx < 10 && gamepan[k][xx][y] == 0) xx += 1;
        xx -= 1;
        gamepan[k][xx][y] = 1;
        gamepan[k][xx-1][y] = 1;
    }
    remove_full_line(k);
    push_line(k);
    remove_ban_line(k);
}

void solve() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        int t, x, y; cin >> t >> x >> y;
        if(t == 1) {
            place(t, x, y, 0); 
            place(t, y, x, 1);
        }
        else if(t == 2) {
            place(t, x, y, 0);
            place(t+1, y, x, 1);
        }
        else if(t == 3) {
            place(t, x, y, 0);
            place(t-1, y, x, 1);
        }
    }

    for(int k = 0; k < 2; k++) {
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 4; j++) {
                sol.second += gamepan[k][i][j];
            }
        }
    }
}

int main() {
    // FASTIO
    solve();
    cout << sol.first << " " << sol.second;
}