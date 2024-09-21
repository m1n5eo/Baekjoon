#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, k, a, b;
    int room[2][7] = {0, };

    cin >> n >> k;
    for(int i = 0; i < n; i++) {
        cin >> a >> b;

        room[a][b] += 1;
    }

    int res = 0;

    for(int i = 0; i < 2; i++) {
        for(int j = 1; j <= 6; j++) {
            if(room[i][j] != 0) {
                res += (room[i][j]-1)/k+1;
            }
        }
    }
    
    cout << res;

    return 0;
}