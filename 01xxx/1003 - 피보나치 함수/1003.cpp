#include <bits/stdc++.h>
using namespace std;

int main() {
    int zero[44] = {1, 0, }, one[44] = {0, 1, };
    for(int i = 2; i <= 40; i++) {
        zero[i] = zero[i-1] + zero[i-2];
        one[i] = one[i-1] + one[i-2];
    }

    int n, t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> n;
        cout << zero[n] << " " << one[n] << "\n";
    }
}
