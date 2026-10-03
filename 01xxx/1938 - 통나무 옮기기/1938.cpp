#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

struct coordinate {
    int x, y, sw;
};

bool isSame(coordinate p, coordinate q) {
    if(p.x == q.x && p.y == q.y && p.sw == q.sw) return true;
    else return false;
}

int main() {
    FASTIO

    int n, cnt = 0;
    coordinate fin, save1 = {-1, -1, 0}, save2 = {-1, -1, 0};

    cin >> n;

    vector<vector<int>> map(n+1, vector<int>(n+1, 0));
    queue<coordinate> bfs;
    vector<vector<vector<bool>>> check(n+1, vector<vector<bool>>(n+1, vector<bool>(2, false)));

    for(int i = 0; i < n; i++) {
        string temp;

        cin >> temp;

        for(int j = 0; j < n; j++) {
            if(temp[j] == '0') map[i][j] = 0;
            else if(temp[j] == '1') map[i][j] = 1;
            else if(temp[j] == 'B') {
                map[i][j] = 0;

                if(save1.x != -1 && bfs.size() == 0) {
                    bfs.push({i, j, save1.x+1 == i? 0 : 1});
                    check[i][j][save1.x+1 == i? 0 : 1] = true;
                }
                else save1 = {i, j, 0};
            }
            else if(temp[j] == 'E') {
                map[i][j] = 9;
                cnt += 1;

                if(save2.x != -1 && cnt == 2) fin = {i, j, save2.x+1 == i? 0 : 1};
                else save2 = {i, j, 0};
            }
        }
    }

    int result = 0;
    bool stop_point = true;

    while(bfs.size() && stop_point) {
        int bfs_size = bfs.size();
        result += 1;

        for(int _ = 0; _ < bfs_size && stop_point; _++) {
            coordinate now = bfs.front();
            bfs.pop();

            if(now.sw == 0) {
                coordinate next;

                next = {now.x-1, now.y, now.sw};
                if(0 <= next.x-1 && next.x-1 < n && 0 <= next.y && next.y < n) {
                    if(map[next.x-1][next.y] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }

                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                next = {now.x+1, now.y, now.sw};
                if(0 <= next.x+1 && next.x+1 < n && 0 <= next.y && next.y < n) {
                    if(map[next.x+1][next.y] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                next = {now.x, now.y-1, now.sw};
                if(0 <= next.x && next.x < n && 0 <= next.y && next.y < n) {
                    if(map[next.x-1][next.y] != 1 && map[next.x][next.y] != 1 && map[next.x+1][next.y] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                next = {now.x, now.y+1, now.sw};
                if(0 <= next.x && next.x < n && 0 <= next.y && next.y < n) {
                    if(map[next.x-1][next.y] != 1 && map[next.x][next.y] != 1 && map[next.x+1][next.y] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                bool stop = true;
                next = {now.x, now.y, 1-now.sw};
                for(int i = -1; i <= 1 && stop; i++) {
                    for(int j = -1; j <= 1 && stop; j++) {
                        if(!(0 <= next.x+i && next.x+i < n && 0 <= next.y+j && next.y+j < n) || map[next.x+i][next.y+j] == 1) stop = false;
                        else if(i == 1 && j == 1) {
                            if(check[next.x][next.y][next.sw] == false) {
                                if(isSame(next, fin) == true) {
                                    stop_point = false;
                                    break;
                                }
                        
                                bfs.push({next.x, next.y, next.sw});
                                check[next.x][next.y][next.sw] = true;
                            }
                        }
                    }
                }
            }
            else if(now.sw == 1) {
                coordinate next;

                next = {now.x-1, now.y, now.sw};
                if(0 <= next.x && next.x < n && 0 <= next.y && next.y < n) {
                    if(map[next.x][next.y-1] != 1 && map[next.x][next.y] != 1 && map[next.x][next.y+1] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                next = {now.x+1, now.y, now.sw};
                if(0 <= next.x && next.x < n && 0 <= next.y && next.y < n) {
                    if(map[next.x][next.y-1] != 1 && map[next.x][next.y] != 1 && map[next.x][next.y+1] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                next = {now.x, now.y-1, now.sw};
                if(0 <= next.x && next.x < n && 0 <= next.y-1 && next.y-1 < n) {
                    if(map[next.x][next.y-1] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                next = {now.x, now.y+1, now.sw};
                if(0 <= next.x && next.x < n && 0 <= next.y+1 && next.y+1 < n) {
                    if(map[next.x][next.y+1] != 1 && check[next.x][next.y][next.sw] == false) {
                        if(isSame(next, fin) == true) {
                            stop_point = false;
                            break;
                        }
                        
                        bfs.push({next.x, next.y, next.sw});
                        check[next.x][next.y][next.sw] = true;
                    }
                }

                bool stop = true;
                next = {now.x, now.y, 1-now.sw};
                for(int i = -1; i <= 1 && stop; i++) {
                    for(int j = -1; j <= 1 && stop; j++) {
                        if(!(0 <= next.x+i && next.x+i < n && 0 <= next.y+j && next.y+j < n) || map[next.x+i][next.y+j] == 1) stop = false;
                        else if(i == 1 && j == 1) {
                            if(check[next.x][next.y][next.sw] == false) {
                                if(isSame(next, fin) == true) {
                                    stop_point = false;
                                    break;
                                }
                        
                                bfs.push({next.x, next.y, next.sw});
                                check[next.x][next.y][next.sw] = true;
                            }
                        }
                    }
                }
            }
        }
    }

    if(stop_point == false) cout << result;
    else cout << 0;
}