#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n%2 == 0 || !(1 <= n && n <= 50)) {
        cout << "INPUT ERROR!";
        return 0;
    }

    n = n/2+1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    for(int i = n-1; i >= 1; i--) {
        for(int j = 1; j <= i; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
}