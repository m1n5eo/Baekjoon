#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    int n, x;
    char str[11];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%s", str);
        if(str[0] == 'p' && str[1] == 'u') {
            scanf("%d", &x);
            st.push(x);
        }
        else if(str[0] == 'p' && str[1] == 'o') {
            if(st.empty()) printf("-1\n");
            else {
                printf("%d\n", st.top());
                st.pop();
            }
        }
        else if(str[0] == 's') printf("%d\n", st.size());
        else if(str[0] == 'e') printf("%d\n", st.empty());
        else if(str[0] == 't') {
            if(st.empty()) printf("-1\n");
            else printf("%d\n", st.top());
        }
    }
}
