#include <iostream>
using namespace std;

char arr[111][111];

int main() {
    int n;
    cin >> n;

    int ii = 0, jj = n-1;
    char cnt = 'A';
    while(true) {
        arr[ii][jj] = cnt;
        if(cnt == 'Z') cnt = 'A';
        else cnt += 1;

        if(ii == n-1 && jj == n-1) break;

        if(ii == n-1) {
            ii = jj+1;
            jj = n-1;
        }
        else {
            ii = ii+1;
            jj = jj-1;
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i][j] == 0) cout << "  ";
            else cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}