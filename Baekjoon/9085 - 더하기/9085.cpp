#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t, n, num[11];

    cin >> t;

    for(int i = 0; i < t; i++) {
        int sum = 0;

        cin >> n;

        for(int i = 0; i < n; i++) {
            cin >> num[i];

            sum += num[i];
        }

        cout << sum << "\n";
    }

    return 0;
}