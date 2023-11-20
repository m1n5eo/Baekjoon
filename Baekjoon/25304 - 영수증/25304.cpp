#include <bits/stdc++.h>

using namespace std;

int main() {
    int money, n, a, b, sum = 0;
    cin >> money;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        cin >> b;
        sum += a*b;
    }
    if(sum == money) cout << "Yes";
    else cout << "No";
}
