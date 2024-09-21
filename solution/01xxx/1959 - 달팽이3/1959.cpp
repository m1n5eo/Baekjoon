#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    long long int n, m;

    cin >> n >> m;

    if(n > m) cout << m*2-1 << "\n";
    else if(n <= m) cout << (n-1)*2 << "\n";

    if(n > m) {
        if(n%2 == 0) {
            if(m%2 == 0) cout << m/2+1 << " " << m/2;
            else if(m%2 == 1) cout << n/2+(n-m)/2+1 << " " << m/2+1;
        }
        else if(n%2 == 1) {
            if(m%2 == 0) cout << (n+1)/2-(n-m)/2 << " " << m/2;
            else if(m%2 == 1) cout << (n+1)/2+(n-m)/2 << " " << m/2+1;
        }
    }
    else if(n == m) {
        if(n%2 == 0) cout << n/2+1 << " " << m/2;
        else if(n%2 == 1) cout << n/2+1 << " " << m/2+1;
    }
    else if(n < m) {
        if(n%2 == 0) cout << n/2+1 << " " << n/2;
        else if(n%2 == 1) cout << n/2+1 << " " << n/2+m-n+1;
    }

    return 0;
}