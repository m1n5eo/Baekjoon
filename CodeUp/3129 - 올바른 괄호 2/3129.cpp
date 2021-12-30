#include <bits/stdc++.h>
using namespace std;

int main() {
    char ch[50003];
    gets(ch);
    stack <char> st;
    int len = strlen(ch);
    if(ch[0] == ')') {
        printf("bad");
        return 0;
    }
    for(int i = 0; i < len; i++) {
        if(ch[i] == '(') st.push(ch[i]);
        else if(st.empty() == 1) continue;
        else if(ch[i] == ')') st.pop();
    }
    if(st.empty() == 1) printf("good");
    else printf("bad");
}