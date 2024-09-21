#include <iostream>
using namespace std;

int main() {
    int t, n, f, sum = 0;
    cin >> t >> n;
    for(int i = 0; i < n; i++) {
        cin >> f;
        sum += f;
    }
    if(t > sum) cout << "Padaeng_i Cry";
    else cout << "Padaeng_i Happy";
}