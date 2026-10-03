#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int a[4], b[2];
    for(int i = 0; i < 4; i++) cin >> a[i];
    for(int i = 0; i < 2; i++) cin >> b[i];
    sort(a, a+4); sort(b, b+2);
    cout << a[3]+a[2]+a[1]+b[1];
}