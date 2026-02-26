#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1234567890

vector<int> dx = {-1, 0, 1, 0};
vector<int> dy = {0, 1, 0, -1};

pair<int, int> comp(pair<int, int> a, pair<int, int> b) {
    if(a == b) return a;
    else if(a.first == b.first) return a.second < b.second? a : b;
    else return a.first < b.first? a : b;
}

pair<int, int> backtracking(vector<string> gamepan, int a, int b) {
    pair<int, int> ret = {a, b};
    if(a == 1) return ret;
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 9; j++) {
            if(gamepan[i][j] == 'o') {
                for(int k = 0; k < 4; k++) {
                    pair<int, int> next = {i+dx[k], j+dy[k]};
                    pair<int, int> nnext = {i+dx[k]*2, j+dy[k]*2};
                    if(!(0 <= next.first && next.first < 5 && 0 <= next.second && next.second < 9)) continue;
                    else if(!(0 <= nnext.first && nnext.first < 5 && 0 <= nnext.second && nnext.second < 9)) continue;
                    else if(gamepan[next.first][next.second] != 'o') continue;
                    else if(gamepan[nnext.first][nnext.second] != '.') continue;
                    gamepan[i][j] = '.';
                    gamepan[next.first][next.second] = '.';
                    gamepan[nnext.first][nnext.second] = 'o';
                    ret = comp(ret, backtracking(gamepan, a-1, b+1));
                    gamepan[i][j] = 'o';
                    gamepan[next.first][next.second] = 'o';
                    gamepan[nnext.first][nnext.second] = '.';
                }
            }
        }
    }
    return ret;
}

pair<int, int> solution() {
    int cnt = 0;
    vector<string> gamepan;
    for(int i = 0; i < 5; i++) {
        string temp; cin >> temp;
        gamepan.push_back(temp);
        for(int j = 0; j < 9; j++) {
            if(gamepan[i][j] == 'o') {
                cnt += 1;
            }
        }
    }
    return backtracking(gamepan, cnt, 0);
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) {
        pair<int, int> sol = solution();
        cout << sol.first << " " << sol.second << "\n";
    }
}