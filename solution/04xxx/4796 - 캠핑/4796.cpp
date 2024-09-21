#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    for(int cnt = 1; ; cnt++) {
        int n, m, k;

        cin >> n >> m >> k;

        if(n == 0 && m == 0 && k == 0) {
            break;
        }

        cout << "Case " << cnt << ": ";
        cout << k/m*n + (((k-k/m*m)-1)/n==0?(k-k/m*m):n) << "\n";
    }

    return 0;
}