#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, m, snail[111][111] = {0, };

    cin >> n >> m;

    int i = 0, j = 0, cnt = n*m;
    int res = 0, sw = 0;

    while(cnt) {
        snail[i][j] = cnt;
        cnt = cnt-1;

        if(sw == 0) {
            if(j+1 == m || snail[i][j+1] != 0) {
                if(cnt != 0) res = res+1;

                sw = 1;
                i = i+1;
            }
            else {
                j = j+1;
            }
        }
        else if(sw == 1) {
            if(i+1 == n || snail[i+1][j] != 0) {
                if(cnt != 0) res = res+1;

                sw = 2;
                j = j-1;
            }
            else {
                i = i+1;
            }
        }
        else if(sw == 2) {
            if(j == 0 || snail[i][j-1] != 0) {
                if(cnt != 0) res = res+1;

                sw = 3;
                i = i-1;
            }
            else {
                j = j-1;
            }
        }
        else if(sw == 3) {
            if(i == 0 || snail[i-1][j] != 0) {
                if(cnt != 0) res = res+1;
                
                sw = 0;
                j = j+1;
            }
            else {
                i = i-1;
            }
        }
    }

    cout << res;

    return 0;
}