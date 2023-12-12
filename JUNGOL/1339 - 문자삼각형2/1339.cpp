#include <iostream>
using namespace std;

char arr[111][111];

int main() {
    int n;
    cin >> n;
    if(n%2 == 0 || !(1 <= n && n <= 100)) {
        cout << "INPUT ERROR";
        return 0;
    }

    int ii = 0, jj = n/2;
    char cnt = 'A';
    while(true) {
        arr[ii][jj] = cnt;
        if(cnt == 'Z') cnt = 'A';
        else cnt += 1;

        if(ii == n/2 && jj == n-1) break;

        if(jj == n/2+ii) {
            ii = ii+1;
            jj = n/2-ii;
        }
        else jj = jj+1;
    }

    for(int i = 0; i < n; i++) {
        for(int j = n/2; j >= 0; j--) {
            if(arr[j][i] != 0) cout << arr[j][i] << " ";
            else cout << "  ";
        }
        cout << "\n";
    }
}