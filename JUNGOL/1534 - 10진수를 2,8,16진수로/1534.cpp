#include <iostream>
#include <stack>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    stack<char> s;
    while(n) {
        if(0 <= n%k && n%k <= 9) s.push(n%k+'0');
        else s.push(n%k+'A'-10);
        n = n/k;
    }

    int len = s.size();
    for(int i = 0; i < len; i++) {
        cout << s.top();
        s.pop();
    }
}