#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int n, m;

    cin >> n >> m;

    if(n > m) {
        cout << m*2-1;
    }
    else if(n <= m) {
        cout << (n-1)*2;
    }

    return 0;
}