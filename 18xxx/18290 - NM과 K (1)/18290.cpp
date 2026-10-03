#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 11
#define INF 1234567890

int n, m, p, result = -INF, arr[MAX][MAX];
bool visit[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void bt(int x, int y, int sum, int cnt) {
    if(cnt == p) {
        result = max(result, sum);
        return;
    }

    visit[x][y] = true;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(visit[i][j] == false) {
                bool stop_point = true;

                for(int k = 0; k < 4 && stop_point; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if(visit[nx][ny] == true) stop_point = false;
                    }
                }

                if(stop_point == true) {
                    bt(i, j, sum+arr[i][j], cnt+1);
                }
            }
        }
    }

    visit[x][y] = false;
}

int main() {
    FASTIO

    cin >> n >> m >> p;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            bt(i, j, arr[i][j], 1);
        }
    }

    cout << result;
}