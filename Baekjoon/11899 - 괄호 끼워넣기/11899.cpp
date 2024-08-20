#include <iostream>
#include <string>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);

int main() {
    FASTIO

    string str;
    stack<char> st;

    cin >> str;

    int str_size = str.size(), cnt = 0;

    for(int i = 0; i < str_size; i++) {
        if(str[i] == '(') st.push('(');
        else if(str[i] == ')' && st.size()) st.pop();
        else if(str[i] == ')' && st.size() == 0) cnt += 1;
    }

    cout << cnt + st.size();
}