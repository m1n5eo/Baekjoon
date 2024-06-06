#include <iostream>
#include <string>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    string a, b, c;

    cin >> a >> b >> c;

    cout << stoi(a)+stoi(b)-stoi(c) << "\n";
    cout << stoi(a+b)-stoi(c);
}