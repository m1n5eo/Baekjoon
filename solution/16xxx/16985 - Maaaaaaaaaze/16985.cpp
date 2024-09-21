#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define INF 2100000000

struct point {
    int _z, _x, _y, _cnt;
};

int m, result = INF, cube[5][5][5], save[5][5][5];
bool visit[5][5][5], check[5];
queue<point> bfs;

int dx[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 1, 0, 0};
int dz[6] = {0, 0, 0, 0, -1, 1};

int stacking[122][5];

void rotation(int idx) {
    int temp[5][5];

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            temp[j][5-i-1] = cube[idx][i][j];
        }
    }

    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < 5; j++) {
            cube[idx][i][j] = temp[i][j];
        }
    }
}

int main() {
    FASTIO

    for(int k0 = 0; k0 < 5; k0++) {
        if(check[k0] == true) continue;
        check[k0] = true;
        for(int k1 = 0; k1 < 5; k1++) {
            if(check[k1] == true) continue;
            check[k1] = true;
            for(int k2 = 0; k2 < 5; k2++) {
                if(check[k2] == true) continue;
                check[k2] = true;
                for(int k3 = 0; k3 < 5; k3++) {
                    if(check[k3] == true) continue;
                    check[k3] = true;
                    for(int k4 = 0; k4 < 5; k4++) {
                        if(check[k4] == true) continue;
                        stacking[m][0] = k0;
                        stacking[m][1] = k1;
                        stacking[m][2] = k2;
                        stacking[m][3] = k3;
                        stacking[m][4] = k4;
                        m += 1;
                    }
                    check[k3] = false;
                }
                check[k2] = false;
            }
            check[k1] = false;
        }
        check[k0] = false;
    }

    for(int k = 0; k < 5; k++) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cin >> cube[k][i][j];
            }
        }
    }

    for(int k0 = 0; k0 < 4; k0++) {
        rotation(0);
        for(int k1 = 0; k1 < 4; k1++) {
            rotation(1);
            for(int k2 = 0; k2 < 4; k2++) {
                rotation(2);
                for(int k3 = 0; k3 < 4; k3++) {
                    rotation(3);
                    for(int k4 = 0; k4 < 4; k4++) {
                        rotation(4);

                        for(int k = 0; k < 5; k++) {
                            for(int i = 0; i < 5; i++) {
                                for(int j = 0; j < 5; j++) {
                                    save[k][i][j] = cube[k][i][j];
                                }
                            }
                        }

                        for(int ii = 0; ii < m; ii++) {
                            for(int k = 0; k < 5; k++) {
                                for(int i = 0; i < 5; i++) {
                                    for(int j = 0; j < 5; j++) {
                                        cube[k][i][j] = save[stacking[ii][k]][i][j];
                                    }
                                }
                            }

                            if(cube[0][0][0] == 1 && cube[4][4][4] == 1) {
                                bool stop_point = true;

                                bfs.push({0, 0, 0, 1});
                                visit[0][0][0] = true;

                                while(bfs.size()) {
                                    int x = bfs.front()._x;
                                    int y = bfs.front()._y;
                                    int z = bfs.front()._z;
                                    int cnt = bfs.front()._cnt;

                                    bfs.pop();

                                    for(int p = 0; p < 6 && stop_point; p++) {
                                        int nx = x+dx[p];
                                        int ny = y+dy[p];
                                        int nz = z+dz[p];

                                        if(0 <= nx && nx < 5 && 0 <= ny && ny < 5 && 0 <= nz && nz < 5) {
                                            if(nx == 4 && ny == 4 && nz == 4) {
                                                result = min(result, cnt);
                                                while(bfs.size()) bfs.pop();
                                                stop_point = false;
                                            }
                                            else if(cube[nz][nx][ny] == 1 && visit[nz][nx][ny] == false) {
                                                bfs.push({nz, nx, ny, cnt+1});
                                                visit[nz][nx][ny] = true;
                                            }
                                        }
                                    }
                                }

                                for(int k = 0; k < 5; k++) {
                                    for(int i = 0; i < 5; i++) {
                                        for(int j = 0; j < 5; j++) {
                                            visit[k][i][j] = false;
                                        }
                                    }
                                }
                            }
                        }

                        for(int k = 0; k < 5; k++) {
                            for(int i = 0; i < 5; i++) {
                                for(int j = 0; j < 5; j++) {
                                    cube[k][i][j] = save[k][i][j];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(result == INF) cout << -1;
    else cout << result;
}