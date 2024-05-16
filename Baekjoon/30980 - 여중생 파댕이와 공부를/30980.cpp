#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
string str[222];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;
    for(int i = 0; i < n*3; i++) {
        cin >> str[i];
    }

    for(int i = 1; i < n*3; i+=3) {
        for(int j = 1; j < m*8; j+=8) {
            int a = str[i][j]-'0';
            int b = str[i][j+2]-'0';
            int c = str[i][j+4]-'0';

            if(str[i][j+5] != '.') {
                c = c*10 + (str[i][j+5]-'0');
            }

            if(a+b == c) {
                if(str[i][j+5] == '.') {
                    for(int k = j; k < j+5; k++) {
                        str[i-1][k] = '*';
                        str[i+1][k] = '*';
                    }
                    str[i][j-1] = '*';
                    str[i][j+5] = '*';
                }
                else if(str[i][j+5] != '.'){
                    for(int k = j; k < j+6; k++) {
                        str[i-1][k] = '*';
                        str[i+1][k] = '*';
                    }
                    str[i][j-1] = '*';
                    str[i][j+6] = '*';
                }
            }
            else if(a+b != c) {
                str[i-1][j+2] = '/';
                str[i][j+1] = '/';
                str[i+1][j] = '/';
            }
        }
    }

    for(int i = 0; i < n*3; i++) {
        for(int j = 0; j < m*8; j++) {
            cout << str[i][j];
        }
        cout << "\n";
    }

    return 0;
}