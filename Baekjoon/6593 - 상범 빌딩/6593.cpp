#include <iostream>
#include <queue>
#include <tuple>
#include <string>
using namespace std;

int l, r, c, stop_point;
int building[33][33][33];
bool visited[33][33][33];
queue<tuple<int, int, int>> q;

int dx[6] = {0, 0, 0, 0, -1, 1};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int dz[6] = {0, 1, 0, -1, 0, 0};

void init() {
    while(q.size()) {
        q.pop();
    }

    for(int i = 0; i < l; i++) {
        for(int j = 0; j < r; j++) {
            for(int k = 0; k < c; k++) {
                visited[i][j][k] = false;
                building[i][j][k] = 0;
            }
        }
    }
    
    stop_point = 0;

    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    while(true) {
        cin >> l >> r >> c;

        if(l == 0 && r == 0 && c == 0) {
            return 0;
        }

        for(int i = 0; i < l; i++) {
            for(int j = 0; j < r; j++) {
                string str;
                cin >> str;

                for(int k = 0; k < c; k++) {
                    if(str[k] == '#') {
                        building[i][j][k] = -1;
                    }
                    else if(str[k] == 'E') {
                        building[i][j][k] = -2;
                    }
                    else if(str[k] == '.') {
                        building[i][j][k] = 0;
                    }
                    else if(str[k] == 'S') {
                        building[i][j][k] = 0;
                        visited[i][j][k] = true;

                        q.push(make_tuple(i, j, k));
                    }
                }
            }
        }

        while(q.size() && stop_point == 0) {
            int x = get<0>(q.front());
            int y = get<1>(q.front());
            int z = get<2>(q.front());

            q.pop();

            for(int t = 0; t < 6; t++) {
                int nx = x+dx[t];
                int ny = y+dy[t];
                int nz = z+dz[t];

                if(0 <= nx && nx < l && 0 <= ny && ny < r && 0 <= nz && nz < c) {
                    if(visited[nx][ny][nz] == true) {
                        continue;
                    }
                    else if(building[nx][ny][nz] == 0) {
                        building[nx][ny][nz] = building[x][y][z]+1;
                        visited[nx][ny][nz] = true;

                        q.push(make_tuple(nx, ny, nz));
                    }
                    else if(building[nx][ny][nz] == -2) {
                        stop_point = 1;

                        cout << "Escaped in " << building[x][y][z]+1 << " minute(s).\n";
                        break;
                    }
                }
            }
        }

        if(stop_point == 0) {
            cout << "Trapped!\n";
        }

        init();
    }
}