#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if(!(1 <= n && n <= 100) || !(1 <= m && m <= 3)) {
        cout << "INPUT ERROR!";
        return 0;
    }

    if(m == 1) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < i; j++) cout << "*";
            cout << "\n";
        }
    }
    else if(m == 2) {
        for(int i = n; i >= 1; i--) {
            for(int j = 0; j < i; j++) cout << "*";
            cout << "\n";
        }
    }
    else if(m == 3) {
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j < n-i; j++) cout << " ";
            for(int j = 0; j < i*2-1; j++) cout << "*";
            cout << "\n";
        }
    }
}