#include <iostream>
#include <algorithm>
using namespace std;

int n, x, y, max_x = -11111, min_x = 11111, max_y = -11111, min_y = 11111;

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> x >> y;
        min_x = min(x, min_x);
        max_x = max(x, max_x);
        min_y = min(y, min_y);
        max_y = max(y, max_y);
    }
    cout << (max_x-min_x)*(max_y-min_y);
}