#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    int a, b;
    string s;

    while(true) {
        cin >> a;
        if(a == 0) break;
        cin >> s >> b;

        long long int temp = 1, num = 0, len = s.size();
        for(int i = len-1; i >= 0; i--) {
            if('0' <= s[i] && s[i] <= '9') num += temp*(s[i]-'0');
            else if('A' <= s[i] && s[i] <= 'Z') num += temp*(s[i]-'A'+10);
            temp *= a;
        }

        stack<char> res;
        temp = 1;
        do {
            if(0 <= num%b && num%b < 10) res.push(num%b+'0');
            else if(10 <= num%b && num%b < 36) res.push(num%b+'A'-10);
            num = num/b;
        } while(num);

        len = res.size();
        for(int i = 0; i < len; i++) {
            cout << res.top();
            res.pop();
        }
        cout << "\n";
    }
}