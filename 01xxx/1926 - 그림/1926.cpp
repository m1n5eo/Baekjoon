#include <iostream>
#include <algorithm>
using namespace std;

int n, m, cnt, area, max_area;
int picture[555][555];
bool visited[555][555];

void bfs(int x, int y) {
    visited[x][y] = true;
    area += 1;

    if(x > 0 && picture[x-1][y] == 1 && visited[x-1][y] == false) bfs(x-1, y); 
    if(x < n && picture[x+1][y] == 1 && visited[x+1][y] == false) bfs(x+1, y); 
    if(y > 0 && picture[x][y-1] == 1 && visited[x][y-1] == false) bfs(x, y-1); 
    if(y < m && picture[x][y+1] == 1 && visited[x][y+1] == false) bfs(x, y+1);

    return;
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> picture[i][j];
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(picture[i][j] == 1 && visited[i][j] == false) {
                cnt += 1;
                area = 0;

                bfs(i, j);

                max_area = max(max_area, area);
            }
        }
    }

    cout << cnt << "\n" << max_area;

    return 0;
}