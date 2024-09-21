#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string str;
    
    cin >> str;

    int len = str.length();
    stack<int> res;

    for(int i = len-1; i >= 0; i-=3) {
        if(i-2 >= 0) {
            res.push((str[i]-'0') + (str[i-1]-'0')*2 + (str[i-2]-'0')*4);
        }
        else if(i-1 >= 0) {
            res.push((str[i]-'0') + (str[i-1]-'0')*2);
        }
        else {
            res.push(str[i]-'0');
        }
    }

    while(!res.empty()) {
        cout << res.top();
        res.pop();
    }

    return 0;
}