#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        if(i%2 == 0) {
            for(int j = 1; j <= n; j++) cout << j << " ";
        }
        else if(i%2 == 1) {
            for(int j = n; j >= 1; j--) cout << j << " ";
        }
        cout << "\n";
    }
}