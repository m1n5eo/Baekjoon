#include <bits/stdc++.h>
using namespace std;

int n, a, b, answer;

void Z(int x, int y, int num) {
    if(x == a && y == b) {
        cout << answer << "\n";
        return;
    }

    if(a < x+num && a >= x && b < y+num && b >= y) {
        Z(x, y, num/2);
        Z(x, y+num/2, num/2);
        Z(x+num/2, y, num/2);
        Z(x+num/2, y+num/2, num/2);
    }
    else answer += num*num;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> a >> b;
    Z(0, 0, 1 << n);
}