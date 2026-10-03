#include <iostream>
#include <string>
using namespace std;

#define MAX 1111

int n, m, cnt;
int map[MAX][MAX], parent[MAX*MAX];
bool visit[MAX][MAX], parent_visit[MAX*MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int Find(int x) {
    if(x == parent[x]) return x;
    else return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x > y) parent[x] = y;
    else parent[y] = x;
}

bool isSame(int x, int y) {
    x = Find(x);
    y = Find(y);

    if(x == y) return true;
    else return false;
}

void dfs(int x, int y) {
    if(x < 0 || x >= n || y < 0 || y >= m) return;
    else if(visit[x][y] == true) return;

    int nx = x+dx[map[x][y]];
    int ny = y+dy[map[x][y]];

    visit[x][y] = true;

    Union(x*m+y, nx*m+ny);
    dfs(nx, ny);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < m; j++) {
            if(str[j] == 'U') map[i][j] = 0;
            else if(str[j] == 'R') map[i][j] = 1;
            else if(str[j] == 'D') map[i][j] = 2;
            else if(str[j] == 'L') map[i][j] = 3;

            parent[i*m+j] = i*m+j;
        }
    }
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visit[i][j] == false) {
                dfs(i, j);
            }
        }
    }
    
    for(int i = 0; i < n*m; i++) {
        int now = Find(i);

        if(parent_visit[now] == false) {
            parent_visit[now] = true;
            cnt += 1;
        }
    }

    cout << cnt;
}