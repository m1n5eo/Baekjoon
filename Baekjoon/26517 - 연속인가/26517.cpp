#include <iostream>
using namespace std;

long long int k, a, b, c, d;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    cin >> k;
    cin >> a >> b >> c >> d;

    if((a-c)*k == d-b) cout << "Yes " << a*k+b;
    else cout << "No";

    return 0;
}