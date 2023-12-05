#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int s, e;
    cin >> s >> e;

    if(s < e) {
        for(int i = s; i <= e; i++) {
            for(int j = 1; j <= 9; j++) {
                cout << i << " * " << j << " = " << setw(2) << i*j << "   ";
                if(j%3 == 0) cout << "\n";
            }
            cout << "\n";
        }
    }
    else {
        for(int i = s; i >= e; i--) {
            for(int j = 1; j <= 9; j++) {
                cout << i << " * " << j << " = " << setw(2) << i*j << "   ";
                if(j%3 == 0) cout << "\n";
            }
            cout << "\n";
        }
    }
}