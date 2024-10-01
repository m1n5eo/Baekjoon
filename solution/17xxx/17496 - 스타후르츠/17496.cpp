#include <iostream>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO
    
    int n, t, c, p;

    cin >> n >> t >> c >> p;
    cout << (n-1)/t*c*p;
}