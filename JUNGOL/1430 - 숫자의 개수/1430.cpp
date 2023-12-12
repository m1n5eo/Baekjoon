#include <iostream>
#include <string>
using namespace std;

int arr[11];

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    string s = to_string(a*b*c);
    for(int i = 0; i < s.length(); i++) {
        arr[s[i]-'0'] += 1;
    }
    for(int i = 0; i < 10; i++) cout << arr[i] << "\n";
}