#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    long long int n, m;

    cin >> n >> m;

    if(n > m) {
        long long int temp = n;
        n = m;
        m = temp;
    }
    else if(n == m) {
        cout << 0 << "\n";
        
        return 0;
    }

    cout << m-n-1 << "\n";
    for(long long int i = n+1; i <= m-1; i++) {
        cout << i << " ";
    }

    return 0;
}