#include <iostream>
#include <string>
using namespace std;

int n, m, cnt;
string str1[55], str2[55];

void change(int x, int y) {
    for(int i = x; i < x+3; i++) {
        for(int j = y; j < y+3; j++) {
            if(str1[i][j] == '0') str1[i][j] = '1';
            else if(str1[i][j] == '1') str1[i][j] = '0';
        }
    }
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        cin >> str1[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> str2[i];
    }

    for(int i = 0; i < n-2; i++) {
        for(int j = 0; j < m-2; j++) {
            if(str1[i][j] != str2[i][j]) {
                change(i, j);
                cnt += 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(str1[i][j] != str2[i][j]) {
                cout << -1;
                return 0;
            }
        }
    }

    cout << cnt;

    return 0;
}