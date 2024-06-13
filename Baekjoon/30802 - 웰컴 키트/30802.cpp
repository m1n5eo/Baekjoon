#include <iostream>
using namespace std;

int n, t, p, cnt, arr[6];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < 6; i++) cin >> arr[i];
    cin >> t >> p;

    for(int i = 0; i < 6; i++) {
        cnt += ((arr[i]+t-1)/t);
    }

    cout << cnt << "\n";
    cout << n/p << " " << n%p;
}