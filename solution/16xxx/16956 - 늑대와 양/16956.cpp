#include <iostream>
#include <string>
using namespace std;

int n, m;
int map[555][555];
string str;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str;
        for(int j = 0; j < m; j++) {
            if(str[j] == '.') map[i][j] = 0;
            else if(str[j] == 'S') map[i][j] = 1;
            else if(str[j] == 'W') map[i][j] = 2;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 1) {
                for(int k = 0; k < 4; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];
                    
                    if(0 <= nx && nx < n && 0 <= ny && ny < m) {
                        if(map[nx][ny] == 2) {
                            cout << 0;
                            exit(0);
                        }
                    }
                }
            }
        }
    }

    cout << 1 << "\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(map[i][j] == 0) cout << 'D';
            else if(map[i][j] == 1) cout << 'S';
            else if(map[i][j] == 2) cout << 'W';
        }
        cout << "\n";
    }

    return 0;
}