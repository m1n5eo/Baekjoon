#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    int tc;

    cin >> tc;

    for(int testcase = 0; testcase < tc; testcase++) {
        string str;
        stack<char> st;
        bool stop_point = true;
        
        cin >> str;

        for(char strs : str) {
            if(strs == '(') st.push('(');
            else {
                if(st.size() == 0) {
                    stop_point = false;
                    break;
                }
                else st.pop();
            }
        }

        if(stop_point == true && st.size() == 0) cout << "YES" << "\n";
        else cout << "NO" << "\n";
    }
}