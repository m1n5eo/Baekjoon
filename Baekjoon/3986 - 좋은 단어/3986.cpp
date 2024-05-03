#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);

    int n, res = 0;

    cin >> n;

    for(int t = 0; t < n; t++) {
        string str;
        stack<char> st;

        cin >> str;

        int len = str.length();
        
        for(int i = 0; i < len; i++) {
            if(st.size() == 0) {
                st.push(str[i]);
            }
            else if(st.top() != str[i]) {
                st.push(str[i]);
            }
            else if(st.top() == str[i]) {
                st.pop();
            }
        }

        if(st.size() == 0) res += 1;
    }

    cout << res;
    
    return 0;
}