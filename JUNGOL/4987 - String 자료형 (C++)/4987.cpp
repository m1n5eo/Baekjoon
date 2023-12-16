#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    while(true) {
        if(!(0 <= s.find(t) && s.find(t) < s.length())) break;
        s.erase(s.find(t), t.length());
    }
    cout << s;
}