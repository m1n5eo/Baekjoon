#include <iostream>

using namespace std;

int n, m, cnt[111];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        cnt[m]++;
    }
    cin >> m;
    cout << cnt[m];
}