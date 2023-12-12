#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    if(n%2 == 0 || !(1 <= n && n <= 100)) {
        cout << "INPUT ERROR!";
        return 0;
    }

    for(int i = n/2+1; i >= 1; i--) {
        for(int j = 0; j < n/2-i+1; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << "\n";
    }
    for(int i = 2; i <= n/2+1; i++) {
        for(int j = 0; j < n/2; j++) cout << " ";
        for(int j = 0; j < i; j++) cout << "*";
        cout << "\n";
    }
}