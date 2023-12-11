#include <iostream>
using namespace std;

int main() {
    int n, m, arr[111][111];
    cin >> n >> m;

    int cnt = 1, sw = 1, ii = 0, jj = 0;
    while(true) {
        arr[ii][jj] = cnt++;

        if(n%2 == 0 && ii == n-1 && jj == 0) break;
        else if(n%2 == 1 && ii == n-1 && jj == m-1) break;

        if(sw == 1) {
            if(jj+1 > m-1) {
                sw = -1;
                ii = ii+1;
            }
            else jj = jj+1;
        }
        else if(sw == -1) {
            if(jj-1 < 0) {
                sw = 1;
                ii = ii+1;
            }
            else jj = jj-1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}