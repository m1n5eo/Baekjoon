#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while(true) {
        cin >> s;
        if(s == "0") break;

        int sum = 0, sw = 0;
        for(int i = s.length()-1; i >= 0; i--) {
            if(sw == 0 && s[i] == '0') continue;
            else sw = 1;
            cout << s[i];
            sum += s[i]-'0';
        }
        cout << " " << sum << "\n";
    }
}