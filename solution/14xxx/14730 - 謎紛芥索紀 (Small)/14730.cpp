#include <iostream>
using namespace std;

int n, c, k;
long long int res;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> c >> k;
        res += c*k;
    }

    cout << res;
    return 0;
}