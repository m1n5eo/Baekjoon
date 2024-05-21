#include <iostream>
using namespace std;

int t, n, a, cnt;
double b, sum;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> t;
    while(t--) {
        cin >> n;
        for(int i = 0; i < n; i++) {
            cin >> a >> b;

            cnt += a;
            sum += b*a;
        }

        cout << cnt << " ";
        cout << fixed;
        cout.precision(1);
        cout << sum/cnt << "\n";

        cnt = 0, sum = 0;
    }
}