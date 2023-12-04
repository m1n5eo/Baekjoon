#include <iostream>
using namespace std;

long long int factorial(int num) {
    if(num == 0) return 1;
    return factorial(num-1) * num;
}

int main() {
    int n;
    cin >> n;
    cout << factorial(n);
}