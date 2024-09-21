#include <bits/stdc++.h>
using namespace std;

stack<char> st;

void initialization() {
    if(st.empty()) return;
    st.pop();
    initialization();
}

int main() {
    int n;
    char str[50];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int sw = 1;
        scanf("%s", str);
        int len = strlen(str);
        for(int j = 0; j < len; j++) {
            if(str[j] == '(') st.push('(');
            else if(str[j] == ')') {
                if(st.empty()) {
                    printf("NO\n");
                    sw = 0;
                    break;
                }
                st.pop();
            }
        }
        if(st.empty() && sw) printf("YES\n");
        else if(sw) printf("NO\n");
        initialization();
    }
}
