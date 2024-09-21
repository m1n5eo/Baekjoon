#include <iostream>

using namespace std;

int n, m, cnt[555];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> m;
        cnt[m+200]++;
    }
    cin >> m;
    cout << cnt[m+200];
}