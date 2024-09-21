#include <iostream>
#include <string>
using namespace std;

int n, sw, prt[11][11];
string pan[11], res[11];

int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1};

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pan[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> res[i];
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(res[i][j] == 'x' && pan[i][j] == '*') sw = 1;
            else if(res[i][j] == 'x') {
                int cnt = 0;

                for(int k = 0; k < 8; k++) {
                    int nx = i+dx[k];
                    int ny = j+dy[k];

                    if(0 <= nx && nx < n && 0 <= ny && ny < n) {
                        if(pan[nx][ny] == '*') cnt += 1;
                    }
                }

                prt[i][j] = cnt;
            }
            else if(res[i][j] == '.') {
                prt[i][j] = -1;
            }
        }
    }

    if(sw == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(pan[i][j] == '*') cout << '*';
                else if(prt[i][j] == -1) cout << '.';
                else cout << prt[i][j];
            }
            cout << "\n";
        }
    }
    else if(sw == 0) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(prt[i][j] == -1) cout << '.';
                else cout << prt[i][j];
            }
            cout << "\n";
        }
    }

    return 0;
}