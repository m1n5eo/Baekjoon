#include <iostream>
using namespace std;

int main() {
    int n;
    long long int sum = 0;

    cin >> n;

    for(int i = 1; i <= n-2; i++) {
        for(int j = 1; j <= n-i-1; j++) {
            sum += i;
        }
    }

    cout << sum << "\n3";
}