#include <bits/stdc++.h>
using namespace std;

int main() {
    stack<int> st;
    int n, sw = 0, arr[100000];
    int stackidx = 1, arridx = 0, stridx = 0;
    char str[300000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    while(stackidx <= n || !st.empty()) {
        if(arridx > n || stackidx > n+1) {
            sw = 1;
            break;
        }
        if(!st.empty() && arr[arridx] == st.top()) {
            st.pop();
            arridx++;
            str[stridx++] = '-';
        }
        else if(arr[arridx] != stackidx) {
            st.push(stackidx++);
            str[stridx++] = '+';
        }
        else if(arr[arridx] == stackidx) {
            st.push(stackidx++);
            str[stridx++] = '+';
            st.pop();
            arridx++;
            str[stridx++] = '-';
        }
    }
    if(sw) printf("NO");
    else for(int i = 0; i < strlen(str); i++) printf("%c\n", str[i]);
}
