#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int s, e;
    while(1) {
        cin >> s >> e;
        if((1 < s && s < 10) && (1 < e && e < 10)) break;
        else cout << "INPUT ERROR!" << "\n";
    }

    if(s < e) {
        for(int j = 1; j <= 9; j++) {
            for(int i = s; i <= e; i++) {
                cout << i << " * " << j << " = " << setw(2) << i*j << "   ";
            }
            cout << "\n";
        }
    }
    else {
        for(int j = 1; j <= 9; j++) {
            for(int i = s; i >= e; i--) {
                cout << i << " * " << j << " = " << setw(2) << i*j << "   ";
            }
            cout << "\n";
        }
    }
}