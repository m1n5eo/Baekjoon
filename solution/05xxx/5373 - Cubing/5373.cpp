#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

vector<vector<vector<char>>> cube(6, vector<vector<char>>(3, vector<char>(3, '-')));

void init() {
    vector<char> color = {'w', 'r', 'y', 'o', 'g', 'b'};
    for(int k = 0; k < 6; k++) {
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                cube[k][i][j] = color[k];
            }
        }
    }
}

vector<vector<char>> rotate_front(int k) {
    vector<vector<char>> ret = cube[0];
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            ret[i][j] = cube[k][3-j-1][i];
        }
    }
    return ret;
}

void rotate(char where) {
    if(where == 'U') {
        cube[0] = rotate_front(0);
        int a = cube[1][0][0];
        int b = cube[1][0][1];
        int c = cube[1][0][2];
        cube[1][0][0] = cube[5][0][0];
        cube[1][0][1] = cube[5][0][1];
        cube[1][0][2] = cube[5][0][2];
        cube[5][0][0] = cube[3][2][2];
        cube[5][0][1] = cube[3][2][1];
        cube[5][0][2] = cube[3][2][0];
        cube[3][2][2] = cube[4][0][0];
        cube[3][2][1] = cube[4][0][1];
        cube[3][2][0] = cube[4][0][2];
        cube[4][0][0] = a;
        cube[4][0][1] = b;
        cube[4][0][2] = c;
    }
    else if(where == 'F') {
        cube[1] = rotate_front(1);
        int a = cube[0][2][0];
        int b = cube[0][2][1];
        int c = cube[0][2][2];
        cube[0][2][0] = cube[4][2][2];
        cube[0][2][1] = cube[4][1][2];
        cube[0][2][2] = cube[4][0][2];
        cube[4][2][2] = cube[2][0][2];
        cube[4][1][2] = cube[2][0][1];
        cube[4][0][2] = cube[2][0][0];
        cube[2][0][2] = cube[5][0][0];
        cube[2][0][1] = cube[5][1][0];
        cube[2][0][0] = cube[5][2][0];
        cube[5][0][0] = a;
        cube[5][1][0] = b;
        cube[5][2][0] = c;
    }
    else if(where == 'D') {
        cube[2] = rotate_front(2);
        int a = cube[1][2][0];
        int b = cube[1][2][1];
        int c = cube[1][2][2];
        cube[1][2][0] = cube[4][2][0];
        cube[1][2][1] = cube[4][2][1];
        cube[1][2][2] = cube[4][2][2];
        cube[4][2][0] = cube[3][0][2];
        cube[4][2][1] = cube[3][0][1];
        cube[4][2][2] = cube[3][0][0];
        cube[3][0][2] = cube[5][2][0];
        cube[3][0][1] = cube[5][2][1];
        cube[3][0][0] = cube[5][2][2];
        cube[5][2][0] = a;
        cube[5][2][1] = b;
        cube[5][2][2] = c;
    }
    else if(where == 'B') {
        cube[3] = rotate_front(3);
        int a = cube[0][0][2];
        int b = cube[0][0][1];
        int c = cube[0][0][0];
        cube[0][0][2] = cube[5][2][2];
        cube[0][0][1] = cube[5][1][2];
        cube[0][0][0] = cube[5][0][2];
        cube[5][2][2] = cube[2][2][0];
        cube[5][1][2] = cube[2][2][1];
        cube[5][0][2] = cube[2][2][2];
        cube[2][2][0] = cube[4][0][0];
        cube[2][2][1] = cube[4][1][0];
        cube[2][2][2] = cube[4][2][0];
        cube[4][0][0] = a;
        cube[4][1][0] = b;
        cube[4][2][0] = c;
    }
    else if(where == 'L') {
        cube[4] = rotate_front(4);
        int a = cube[0][0][0];
        int b = cube[0][1][0];
        int c = cube[0][2][0];
        cube[0][0][0] = cube[3][0][0];
        cube[0][1][0] = cube[3][1][0];
        cube[0][2][0] = cube[3][2][0];
        cube[3][0][0] = cube[2][0][0];
        cube[3][1][0] = cube[2][1][0];
        cube[3][2][0] = cube[2][2][0];
        cube[2][0][0] = cube[1][0][0];
        cube[2][1][0] = cube[1][1][0];
        cube[2][2][0] = cube[1][2][0];
        cube[1][0][0] = a;
        cube[1][1][0] = b;
        cube[1][2][0] = c;
    }
    else if(where == 'R') {
        cube[5] = rotate_front(5);
        int a = cube[0][0][2];
        int b = cube[0][1][2];
        int c = cube[0][2][2];
        cube[0][0][2] = cube[1][0][2];
        cube[0][1][2] = cube[1][1][2];
        cube[0][2][2] = cube[1][2][2];
        cube[1][0][2] = cube[2][0][2];
        cube[1][1][2] = cube[2][1][2];
        cube[1][2][2] = cube[2][2][2];
        cube[2][0][2] = cube[3][0][2];
        cube[2][1][2] = cube[3][1][2];
        cube[2][2][2] = cube[3][2][2];
        cube[3][0][2] = a;
        cube[3][1][2] = b;
        cube[3][2][2] = c;
    }
}

int main() {
    FASTIO
    int tc; cin >> tc;
    while(tc--) {
        int n; cin >> n;
        init();
        for(int i = 0; i < n; i++) {
            string temp; cin >> temp;
            for(int j = 0; j < (temp[1] == '+'? 1 : 3); j++) rotate(temp[0]);
        }

        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) cout << cube[0][i][j];
            cout << "\n";
        }
    }
}