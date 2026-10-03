#include <iostream>
using namespace std;

int a, b, c, n;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> a >> b;
    cin >> c;
    cin >> n;

    if(a*n+b <= c*n && a <= c) cout << 1;
    else cout << 0;
    
    return 0;
}