#include <bits/stdc++.h>
using namespace std;

int sum = 0, cnt = 0;
char str[100001];
stack<char> st;

int main() {
    scanf("%s", str);
    for(int i = 0; i < strlen(str); i++) {
        if(str[i] == '(') st.push('(');
        else if(str[i-1] == '(' && str[i] == ')') {
            st.pop();
            sum += st.size();
        }
        else if(str[i] == ')') {
            st.pop();
            cnt++;
        }
    }
    printf("%d", sum+cnt);
}