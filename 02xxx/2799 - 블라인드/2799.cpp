#include <iostream>
#include <string>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define MAX 111

int n, m, result[5];
string window[MAX*6];

int main() {
    FASTIO

    cin >> n >> m;

    for(int i = 0; i < n*5+1; i++) {
        cin >> window[i];
    }

    for(int i = 1; i < n*5+1; i+=5) {
        for(int j = 1; j < m*5+1; j+=5) {
            for(int k = 0; k <= 4; k++) {
                if(window[i+k][j] != '*') {
                    result[k] += 1;
                    break;
                }
            }
        }
    }

    for(int i = 0; i < 5; i++) {
        cout << result[i] << " ";
    }
}