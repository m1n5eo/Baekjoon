#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define pii pair<int, int>
#define fi first
#define se second
#define MAX 10

int n, m;
vector<vector<int>> gamepan(MAX, vector<int>(MAX, 0));
vector<vector<vector<vector<bool>>>> visited(MAX, vector<vector<vector<bool>>>(MAX, vector<vector<bool>>(MAX, vector<bool>(MAX, false))));

pair<pair<pii, pii>, pair<bool, bool>> tilt(pair<int, int> red, pair<int, int> blue, int mode) {
    pair<bool, bool> check = {false, false};
    if(mode == 0) {
        if(red.fi < blue.fi) {
            for(int i = red.fi; i >= 0; i--) {
                if(gamepan[i][red.se] == 1) {
                    red.fi = i;
                    check.fi = true;
                    break;
                }
                else if(gamepan[i][red.se] == 9) break;
                else if(gamepan[i][red.se] == 0) red.fi = i;
            }
            for(int i = blue.fi; i >= 0; i--) {
                if(gamepan[i][blue.se] == 1) {
                    blue.fi = i;
                    check.se = true;
                    break;
                }
                else if(gamepan[i][blue.se] == 9 || red == make_pair(i, blue.se)) break;
                else if(gamepan[i][blue.se] == 0) blue.fi = i;
            }
        }
        else {
            for(int i = blue.fi; i >= 0; i--) {
                if(gamepan[i][blue.se] == 1) {
                    blue.fi = i;
                    check.se = true;
                    break;
                }
                else if(gamepan[i][blue.se] == 9) break;
                else if(gamepan[i][blue.se] == 0) blue.fi = i;
            }
            for(int i = red.fi; i >= 0; i--) {
                if(gamepan[i][red.se] == 1) {
                    red.fi = i;
                    check.fi = true;
                    break;
                }
                else if(gamepan[i][red.se] == 9 || blue == make_pair(i, red.se)) break;
                else if(gamepan[i][red.se] == 0) red.fi = i;
            }
        }
    }
    else if(mode == 1) {
        if(red.fi > blue.fi) {
            for(int i = red.fi; i < n; i++) {
                if(gamepan[i][red.se] == 1) {
                    red.fi = i;
                    check.fi = true;
                    break;
                }
                else if(gamepan[i][red.se] == 9) break;
                else if(gamepan[i][red.se] == 0) red.fi = i;
            }
            for(int i = blue.fi; i < n; i++) {
                if(gamepan[i][blue.se] == 1) {
                    blue.fi = i;
                    check.se = true;
                    break;
                }
                else if(gamepan[i][blue.se] == 9 || red == make_pair(i, blue.se)) break;
                else if(gamepan[i][blue.se] == 0) blue.fi = i;
            }
        }
        else {
            for(int i = blue.fi; i < n; i++) {
                if(gamepan[i][blue.se] == 1) {
                    blue.fi = i;
                    check.se = true;
                    break;
                }
                else if(gamepan[i][blue.se] == 9) break;
                else if(gamepan[i][blue.se] == 0) blue.fi = i;
            }
            for(int i = red.fi; i < n; i++) {
                if(gamepan[i][red.se] == 1) {
                    red.fi = i;
                    check.fi = true;
                    break;
                }
                else if(gamepan[i][red.se] == 9 || blue == make_pair(i, red.se)) break;
                else if(gamepan[i][red.se] == 0) red.fi = i;
            }
        }
    }
    else if(mode == 2) {
        if(red.se < blue.se) {
            for(int j = red.se; j >= 0; j--) {
                if(gamepan[red.fi][j] == 1) {
                    red.se = j;
                    check.fi = true;
                    break;
                }
                else if(gamepan[red.fi][j] == 9) break;
                else if(gamepan[red.fi][j] == 0) red.se = j;
            }
            for(int j = blue.se; j >= 0; j--) {
                if(gamepan[blue.fi][j] == 1) {
                    blue.se = j;
                    check.se = true;
                    break;
                }
                else if(gamepan[blue.fi][j] == 9 || red == make_pair(blue.fi, j)) break;
                else if(gamepan[blue.fi][j] == 0) blue.se = j;
            }
        }
        else {
            for(int j = blue.se; j >= 0; j--) {
                if(gamepan[blue.fi][j] == 1) {
                    blue.se = j;
                    check.se = true;
                    break;
                }
                else if(gamepan[blue.fi][j] == 9) break;
                else if(gamepan[blue.fi][j] == 0) blue.se = j;
            }
            for(int j = red.se; j >= 0; j--) {
                if(gamepan[red.fi][j] == 1) {
                    red.se = j;
                    check.fi = true;
                    break;
                }
                else if(gamepan[red.fi][j] == 9 || blue == make_pair(red.fi, j)) break;
                else if(gamepan[red.fi][j] == 0) red.se = j;
            }
        }
    }
    else if(mode == 3) {
        if(red.se > blue.se) {
            for(int j = red.se; j < m; j++) {
                if(gamepan[red.fi][j] == 1) {
                    red.se = j;
                    check.fi = true;
                    break;
                }
                else if(gamepan[red.fi][j] == 9) break;
                else if(gamepan[red.fi][j] == 0) red.se = j;
            }
            for(int j = blue.se; j < m; j++) {
                if(gamepan[blue.fi][j] == 1) {
                    blue.se = j;
                    check.se = true;
                    break;
                }
                else if(gamepan[blue.fi][j] == 9 || red == make_pair(blue.fi, j)) break;
                else if(gamepan[blue.fi][j] == 0) blue.se = j;
            }
        }
        else {
            for(int j = blue.se; j < m; j++) {
                if(gamepan[blue.fi][j] == 1) {
                    blue.se = j;
                    check.se = true;
                    break;
                }
                else if(gamepan[blue.fi][j] == 9) break;
                else if(gamepan[blue.fi][j] == 0) blue.se = j;
            }
            for(int j = red.se; j < m; j++) {
                if(gamepan[red.fi][j] == 1) {
                    red.se = j;
                    check.fi = true;
                    break;
                }
                else if(gamepan[red.fi][j] == 9 || blue == make_pair(red.fi, j)) break;
                else if(gamepan[red.fi][j] == 0) red.se = j;
            }
        }
    }
    return {{red, blue}, check};
}

int solve() {
    cin >> n >> m;
    pair<int, int> red, blue;
    for(int i = 0; i < n; i++) {
        string temp; cin >> temp;
        for(int j = 0; j < m; j++) {
            if(temp[j] == '#') gamepan[i][j] = 9;
            else if(temp[j] == 'O') gamepan[i][j] = 1;
            else if(temp[j] == 'R') red = {i, j};
            else if(temp[j] == 'B') blue = {i, j};
        }
    }

    int result = 0;
    queue<pair<pii, pii>> bfs;
    bfs.push({red, blue});
    visited[red.fi][red.se][blue.fi][blue.se] = true;
    while(!bfs.empty()) {
        int bs = bfs.size();
        result += 1;
        for(int _ = 0; _ < bs; _++) {
            pair<pii, pii> now = bfs.front(); bfs.pop();
            for(int k = 0; k < 4; k++) {
                pair<pair<pii, pii>, pair<bool, bool>> next = tilt(now.fi, now.se, k);
                if(next.se.se == true) continue;
                else if(next.se.fi == true) return result;
                else if(visited[next.fi.fi.fi][next.fi.fi.se][next.fi.se.fi][next.fi.se.se]) continue;
                bfs.push(next.fi);
                visited[next.fi.fi.fi][next.fi.fi.se][next.fi.se.fi][next.fi.se.se] = true;
            }
        }
    }
    return -1;
}

int main() {
    FASTIO
    cout << solve();
}