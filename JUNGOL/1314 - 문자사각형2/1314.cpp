#include <iostream>
using namespace std;

int main() {
    char arr[111][111];

    int n;
    cin >> n;

    int ii = 0, jj = 0, sw = 0;
    char cnt = 'A';
    while(true) {
        arr[ii][jj] = cnt;

        if(n%2 == 0 && ii == n-1 && jj == 0) break;
        else if(n%2 == 1 && ii == n-1 && jj == n-1) break;

        if(cnt == 'Z') cnt = 'A';
        else cnt += 1;

        if(sw == 0) {
            if(jj+1 > n-1) {
                sw = 1;
                ii = ii+1;
            }
            else {
                jj = jj+1;
            }
        }
        else if(sw == 1) {
            if(jj-1 < 0) {
                sw = 0;
                ii = ii+1;
            }
            else {
                jj = jj-1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << arr[j][i] << " ";
        }
        cout << "\n";
    }
}