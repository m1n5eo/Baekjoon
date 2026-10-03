#include <iostream>
using namespace std;

int main() {
    int n;
    long long int sum = 0;
    
    cin >> n;
    
    for(int i = 1; i < n; i++) {
        sum += i;
    }

    cout << sum << "\n2";
}