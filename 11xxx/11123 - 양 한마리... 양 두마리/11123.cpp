#include <iostream>
#include <string>
using namespace std;

#define MAX 111

int t, n, m;
bool arr[MAX][MAX], visit[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void dfs(int x, int y) {
    if(!(0 <= x && x < n && 0 <= y && y < m)) return;
    else if(visit[x][y] == true) return;
    else if(arr[x][y] == false) return;

    visit[x][y] = true;

    for(int k = 0; k < 4; k++) {
        int nx = x+dx[k];
        int ny = y+dy[k];

        dfs(nx, ny);
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;

    for(int _ = 0; _ < t; _++) {
        cin >> n >> m;

        for(int i = 0; i < n; i++) {
            string str;
            cin >> str;

            for(int j = 0; j < m; j++) {
                if(str[j] == '#') arr[i][j] = true;
                else arr[i][j] = false;

                visit[i][j] = false;
            }
        }

        int result = 0;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(arr[i][j] == true && visit[i][j] == false) {
                    dfs(i, j);
                    result += 1;
                }
            }
        }

        cout << result << "\n";
    }
}