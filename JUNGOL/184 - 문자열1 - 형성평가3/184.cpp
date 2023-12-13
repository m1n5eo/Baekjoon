#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if('A' <= s[i] && s[i] <= 'Z') cout << char(s[i]+('a'-'A'));
        else if('a' <= s[i] && s[i] <= 'z') cout << s[i];
        else if('0' <= s[i] && s[i] <= '9') cout << s[i];
    }
}