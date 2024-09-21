#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    int t;
    string str;

    cin >> t;
    for(int i = 0; i < t; i++) {
        cin >> str;

        stack<char> pw1, pw2;
        int len = str.length();

        for(int i = 0; i < len; i++) {
            if(str[i] == '<' && pw1.size() != 0) {
                pw2.push(pw1.top());
                pw1.pop();
            }
            else if(str[i] == '>' && pw2.size() != 0) {
                pw1.push(pw2.top());
                pw2.pop();
            }
            else if(str[i] == '-' && pw1.size() != 0) {
                pw1.pop();
            }
            else if('A' <= str[i] && str[i] <= 'Z') {
                pw1.push(str[i]);
            }
            else if('a' <= str[i] && str[i] <= 'z') {
                pw1.push(str[i]);
            }
            else if('0' <= str[i] && str[i] <= '9') {
                pw1.push(str[i]);
            }
        }

        while(!pw1.empty()) {
            pw2.push(pw1.top());
            pw1.pop();
        }

        while(!pw2.empty()) {
            printf("%c", pw2.top());
            pw2.pop();
        }
        printf("\n");
    }
    
    return 0;
}