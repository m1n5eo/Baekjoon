#include <iostream>
using namespace std;

int main() {
    int n, arr[111];
    cin >> n;
    for(int i = 1; ; i*=2) {
        if(n < i) {
            cout << i/2;
            break;
        }
    }
}