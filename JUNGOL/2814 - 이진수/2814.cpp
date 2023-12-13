#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    long long int temp = 1, sum = 0;
    for(int i = s.length()-1; i >= 0; i--) {
        sum += (s[i]-'0')*temp;
        temp *= 2;
    }
    cout << sum;
}