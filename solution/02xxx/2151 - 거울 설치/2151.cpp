#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 1000000000
#define MAX 55

struct type {
    int x, y, direction;
};

int main() {
    FASTIO

    int n, result = -1;
    string temp;
    queue<type> bfs;
    type init;
    vector<vector<int>> house(MAX, vector<int>(MAX, 0));
    vector<vector<vector<bool>>> check(MAX, vector<vector<bool>>(MAX, vector<bool>(4, false)));

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> temp;

        for(int j = 0; j < n; j++) {
            if(temp[j] == '#') {
                house[i][j] = 2;

                if(bfs.size() == 0) {
                    for(int k = 0; k < 4; k++) {
                        int nx = i+dx[k];
                        int ny = j+dy[k];

                        if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                            if(house[nx][ny] != 9) {
                                bfs.push({i, j, k});
                                check[i][j][k] = true;
                                init = {i, j, k};
                            }
                        }
                    }
                }
            }
            else if(temp[j] == '*') house[i][j] = 9;
            else if(temp[j] == '.') house[i][j] = 0;
            else if(temp[j] == '!') house[i][j] = 1;
        }
    }

    while(bfs.size()) {
        int bfs_size = bfs.size();
        result += 1;

        for(int _ = 0; _ < bfs_size; _++) {
            type now = bfs.front(), next;
            bfs.pop();

            for(int dist = 1; (0 <= now.x+dx[now.direction]*dist && now.x+dx[now.direction]*dist < n) && (0 <= now.y+dy[now.direction]*dist && now.y+dy[now.direction]*dist < n) && (house[now.x+dx[now.direction]*dist][now.y+dy[now.direction]*dist] != 9); dist++) {
                next = {now.x+dx[now.direction]*dist, now.y+dy[now.direction]*dist, (now.direction+7)%4};

                if(house[next.x][next.y] == 2 && !(init.x == next.x && init.y == next.y)) {
                    cout << result;
                    exit(0);
                }
                else if(house[next.x][next.y] == 1 && check[next.x][next.y][next.direction] == false) {
                    bfs.push({next.x, next.y, next.direction});
                    check[next.x][next.y][next.direction] = true;
                }

                next = {now.x+dx[now.direction]*dist, now.y+dy[now.direction]*dist, (now.direction+9)%4};

                if(house[next.x][next.y] == 2 && !(init.x == next.x && init.y == next.y)) {
                    cout << result;
                    exit(0);
                }
                else if(house[next.x][next.y] == 1 && check[next.x][next.y][next.direction] == false) {
                    bfs.push({next.x, next.y, next.direction});
                    check[next.x][next.y][next.direction] = true;
                }
            }
        }
    }

    cout << result;
}