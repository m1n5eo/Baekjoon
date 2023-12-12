#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n%2 == 0 || !(1 <= n && n <= 50)) {
        cout << "INPUT ERROR!";
        return 0;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) cout << "  ";
        for(int j = (n-i)*2-1; j > 0; j--) cout << i << " ";
        cout << "\n";
    }
}