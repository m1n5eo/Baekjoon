#include <iostream>
using namespace std;

int cnt[11];

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
        int number = i;

        while(number) {
            cnt[number%10] += 1;
            number /= 10;
        }
    }

    cout << cnt[m];
}