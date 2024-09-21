#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int t, n, m;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n >> m;
        cout << n+m << "\n";
    }
}