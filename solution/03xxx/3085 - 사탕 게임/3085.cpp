#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

#define MAX 55

int n, result, pan[MAX][MAX];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int cnt(int x, int y, int what) {
    int nx = x+dx[what];
    int ny = y+dy[what];

    if((0 <= nx && nx < n && 0 <= ny && ny < n) && pan[nx][ny] == pan[x][y]) return cnt(nx, ny, what) + 1;
    else return 1;
}

int func(int x, int y) {
    int dist1 = cnt(x, y, 0) + cnt(x, y, 2) - 1;
    int dist2 = cnt(x, y, 1) + cnt(x, y, 3) - 1;
    
    return max(dist1, dist2);
}

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;

    for(int i = 0; i < n; i++) {
        string str;
        cin >> str;

        for(int j = 0; j < n; j++) {
            if(str[j] == 'C') pan[i][j] = 0;
            else if(str[j] == 'P') pan[i][j] = 1;
            else if(str[j] == 'Z') pan[i][j] = 2;
            else if(str[j] == 'Y') pan[i][j] = 3;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            swap(pan[i][j], pan[i][j+1]);

            int temp = max(func(i, j), func(i, j+1));
            result = max(result, temp);

            swap(pan[i][j], pan[i][j+1]);
        }
    }
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n; j++) {
            swap(pan[i][j], pan[i+1][j]);

            int temp = max(func(i, j), func(i+1, j));
            result = max(result, temp);

            swap(pan[i][j], pan[i+1][j]);
        }
    }

    cout << result;
}