#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;
    while(s.length() != t.length()) {
        if(t[t.size()-1] == 'A') t.pop_back();
        else if(t[t.size()-1] == 'B') {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if(s == t) cout << "1";
    else cout << "0";
}