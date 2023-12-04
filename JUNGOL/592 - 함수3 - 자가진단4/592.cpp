#include <iostream>
using namespace std;

int print(int num) {
    if(num == 0) return 0;
    return print(num/10) + (num%10)*(num%10);
}

int main() {
    int n;
    cin >> n;
    cout << print(n);
}