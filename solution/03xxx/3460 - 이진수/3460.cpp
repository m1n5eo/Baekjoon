#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    int t, n;

    cin >> t;

    for(int testcase = 0; testcase < t; testcase++) {
        cin >> n;

        for(int i = n, cnt = 0; i > 0; i/=2) {
            if(i%2 == 1) {
                cout << cnt << " ";
            }
            cnt += 1;
        }

        cout << "\n";
    }

    return 0;
}