#include <iostream>
using namespace std;

long long int recursion(int num) {
    if(num == 1) {
        return 1;
    }
    return recursion(num-1)*num;
}

int main() {
    int n;
    cin >> n;
    for(int i = n; i >= 1; i--) {
        if(i == 1) {
            cout << "1! = 1\n";
        }
        else {
            cout << i << "! = " << i << " * " << i-1 << "!\n";
        }
    }
    cout << recursion(n);
}