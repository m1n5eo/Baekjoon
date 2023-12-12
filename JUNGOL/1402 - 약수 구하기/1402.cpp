#include <iostream>
using namespace std;

int main() {
    int n, m, cnt = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        if(n%i == 0) cnt += 1;
        if(cnt == m) {
            cout << i;
            return 0;
        }
    }
    cout << 0;
}