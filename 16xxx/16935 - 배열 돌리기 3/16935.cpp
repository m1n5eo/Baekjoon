#include <iostream>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int n, m, r;
vector<vector<int>> vec(MAX, vector<int>(MAX, 0));

void rotation(int mode) {
    vector<vector<int>> save = vec;

    if(mode == 1) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vec[i][j] = save[n-i-1][j];
            }
        }
    }
    else if(mode == 2) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                vec[i][j] = save[i][m-j-1];
            }
        }
    }
    else if(mode == 3) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec[i][j] = save[n-j-1][i];
            }
        }

        swap(n, m);
    }
    else if(mode == 4) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                vec[i][j] = save[j][m-i-1];
            }
        }

        swap(n, m);
    }
    else if(mode == 5) {
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < m/2; j++) {
                vec[i][j] = save[i+n/2][j];
                vec[i][j+m/2] = save[i][j];
                vec[i+n/2][j] = save[i+n/2][j+m/2];
                vec[i+n/2][j+m/2] = save[i][j+m/2];
            }
        }
    }
    else if(mode == 6) {
        for(int i = 0; i < n/2; i++) {
            for(int j = 0; j < m/2; j++) {
                vec[i][j] = save[i][j+m/2];
                vec[i][j+m/2] = save[i+n/2][j+m/2];
                vec[i+n/2][j] = save[i][j];
                vec[i+n/2][j+m/2] = save[i+n/2][j];
            }
        }
    }
}

int main() {
    FASTIO

    cin >> n >> m >> r;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
        }
    }

    for(int _ = 0; _ < r; _++) {
        int mode;
        cin >> mode;

        rotation(mode);
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << vec[i][j] << " ";
        }
        cout << "\n";
    }
}