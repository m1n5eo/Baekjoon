#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int sum = 0, temp = 1;
    stack<char> st;
    string str;

    cin >> str;
    int len = str.size();
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') st.push('(');
        else if(str[i] == '[') st.push('[');
        else if(str[i] == ')' && !st.empty() && st.top() == '(') st.pop();
        else if(str[i] == ']' && !st.empty() && st.top() == '[') st.pop();
        else {
            cout << sum;
            return 0;
        }
    }
    if(!st.empty()) {
        cout << 0;
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(str[i] == '(') {
            temp *= 2;
            st.push('(');
            if(i+1 < len && str[i+1] == ')') {
                sum += temp;
                temp /= 2;
                st.pop();
                i++;
            }
        }
        else if(str[i] == '[') {
            temp *= 3;
            st.push('[');
            if(i+1 < len && str[i+1] == ']') {
                sum += temp;
                temp /= 3;
                st.pop();
                i++;
            }
        }
        else if(str[i] == ')') {
            st.pop();
            temp /= 2;
        }
        else if(str[i] == ']') {
            st.pop();
            temp /= 3;
        }
    }
    cout << sum;
}