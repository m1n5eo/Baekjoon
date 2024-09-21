#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX 11

struct type {
    int node1, node2, dist;
};

int n, m, idx, result, parent[MAX*MAX], map[MAX][MAX];
queue<pair<int, int>> bfs;
vector<type> v;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool compare(type a, type b) {
    return a.dist < b.dist;
}

int Find(int a) {
    if(a == parent[a]) return a;
    else return parent[a] = Find(parent[a]);
}

bool isSame(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a == b) return true;
    else return false;
}

void Union(int a, int b) {
    a = Find(a);
    b = Find(b);

    if(a > b) parent[a] = b;
    else parent[b] = a;
}

pair<int, int> dfs(int x, int y, int len, int direction) {
    if(!(0 <= x && x < n && 0 <= y && y < m)) return make_pair(0, 0);

    if(map[x][y] != 0) return make_pair(map[x][y], len);
    else return dfs(x+dx[direction], y+dy[direction], len+1, direction);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> map[i][j];

            if(map[i][j] == 1) map[i][j] = -1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == -1) {
                bfs.push({i, j});
                idx += 1;
                map[i][j] = idx;

                while(bfs.size()) {
                    int x = bfs.front().first;
                    int y = bfs.front().second;

                    bfs.pop();

                    for(int k = 0; k < 4; k++) {
                        int nx = x+dx[k];
                        int ny = y+dy[k];

                        if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                            if(map[nx][ny] == -1) {
                                map[nx][ny] = idx;
                                bfs.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] != 0) {
                for(int k = 0; k < 4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if(map[nx][ny] == 0) {
                            pair<int, int> temp = dfs(nx, ny, 0, k);

                            if(temp.second < 2) continue;

                            v.push_back({map[i][j], temp.first, temp.second});
                        }
                    }
                }
            }
        }
    }

    sort(v.begin(), v.end(), compare);

    for(int i = 0; i < idx; i++) {
        parent[i] = i;
    }

    int v_size = v.size();

    for(int i = 0; i < v_size; i++) {
        if(isSame(v[i].node1, v[i].node2) == false) {
            Union(v[i].node1, v[i].node2);
            result += v[i].dist;
        }
    }

    for(int i = 1; i < idx; i++) {
        if(isSame(0, i) == false) {
            cout << -1;
            break;
        }
        else if(i == idx-1) cout << result;
    }
}