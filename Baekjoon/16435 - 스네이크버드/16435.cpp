#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, l, h[11111];
    cin >> n >> l;
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(h, h+n);
    for(int i = 0; i < n; i++) {
        if(h[i] <= l) l++;
    }
    cout << l;
}