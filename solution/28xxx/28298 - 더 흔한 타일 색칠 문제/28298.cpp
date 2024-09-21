#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 555

int n, m, t, cnt[MAX][MAX][33];
char result[MAX][MAX];
string pan[MAX];

int main() {
    FASTIO

    cin >> n >> m >> t;

    for(int i = 0; i < n; i++) {
        cin >> pan[i];
    }

    for(int i = 0; i < n; i+=t) {
        for(int j = 0; j < m; j+=t) {
            for(int x = 0; x < t; x++) {
                for(int y = 0; y < t; y++) {
                    cnt[x][y][pan[i+x][j+y]-'A'] += 1;
                }
            }
        }
    }
    
    for(int i = 0; i < t; i++) {
        for(int j = 0; j < t; j++) {
            int temp = 0;
            int idx = 0;

            for(int k = 'A'-'A'; k <= 'Z'-'A'; k++) {
                if(temp < cnt[i][j][k]) {
                    temp = cnt[i][j][k];
                    idx = k;
                }
            }

            result[i][j] = idx+'A';
        }
    }

    int res = 0;

    for(int i = 0; i < n; i+=t) {
        for(int j = 0; j < m; j+=t) {
            for(int x = 0; x < t; x++) {
                for(int y = 0; y < t; y++) {
                    if(result[x][y] != pan[i+x][j+y]) {
                        pan[i+x][j+y] = result[x][y];
                        res += 1;
                    }
                }
            }
        }
    }

    cout << res << "\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << pan[i][j];
        }
        cout << "\n";
    }
}