#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, sum = 0, a[111], b[111];
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    sort(a, a+n);
    sort(b, b+n);
    for(int i = 0; i < n; i++) {
        sum = sum + a[i]*b[n-i-1];
    }
    cout << sum;
}