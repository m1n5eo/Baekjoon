#include <bits/stdc++.h>
using namespace std;

stack<char> st;

void stackClear() {
    while(!st.empty()) st.pop();
}

int main() {
    char ch, str[111];
    while(1) {
        scanf("%[^\n]s", str);
        if(str[0] == '.' && !str[1]) break;
        for(int i = 0; i < strlen(str); i++) {
            if(str[i] == '(') st.push('(');
            else if(str[i] == '[') st.push('[');
            else if(str[i] == ')') {
                if(st.empty()) {
                    st.push('(');
                    break;
                }
                else if(st.top() == '(') st.pop();
                else if(st.top() == '[') break;
            }
            else if(str[i] == ']') {
                if(st.empty()) {
                    st.push('[');
                    break;
                }
                else if(st.top() == '(') break;
                else if(st.top() == '[') st.pop();
            }
        }
        if(st.empty()) printf("yes\n");
        else printf("no\n");
        stackClear();
        scanf("%c", &ch);
    }
}
