#include <iostream>
#include <string>
using namespace std;

string isPrime(int num) {
    if(num == 1) return "number one";
    for(int i = 2; i*i <= num; i++) {
        if(num%i == 0) return "composite number";
    }
    return "prime number";
}

int main() {
    int n;
    for(int i = 0; i < 5; i++) {
        cin >> n;
        cout << isPrime(n) << "\n";
    }
}