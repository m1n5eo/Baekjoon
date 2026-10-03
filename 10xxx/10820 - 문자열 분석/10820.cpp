#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);

    cin.tie(0);
    cout.tie(0);

    string str;

    while(getline(cin, str)) {
        int lower = 0, upper = 0, number = 0, space = 0;
        int len = str.length();

        for(int i = 0; i < len; i++) {
            if('a' <= str[i] && str[i] <= 'z') {
                lower = lower+1;
            }
            else if('A' <= str[i] && str[i] <= 'Z') {
                upper = upper+1;
            }
            else if('0' <= str[i] && str[i] <= '9') {
                number = number+1;
            }
            else if(str[i] == ' ') {
                space = space+1;
            }
        }

        cout << lower << ' ';
        cout << upper << ' ';
        cout << number << ' ';
        cout << space << '\n';
    }
    
    return 0;
}