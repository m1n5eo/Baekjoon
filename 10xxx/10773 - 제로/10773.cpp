#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    int n, m;
    long long int sum = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &m);
        if(m) st.push(m);
        else st.pop();
    }
    while(!st.empty()) {
        sum += st.top();
        st.pop();
    }
    printf("%lld", sum);
}
