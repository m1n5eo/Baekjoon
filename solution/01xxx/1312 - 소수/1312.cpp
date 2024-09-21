#include <iostream>
using namespace std;

int n, m, k, res;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m >> k;

    for(int i = 0; i < k; i++) {
        n = (n-n/m*m)*10;
        res = n/m;
    }

    cout << res;

    return 0;
}