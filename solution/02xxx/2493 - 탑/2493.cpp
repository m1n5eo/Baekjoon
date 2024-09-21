#include <bits/stdc++.h>
using namespace std;

stack<pair<int,int>> st;
int n, temp;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;
        while(st.size()) {
            if(st.top().first > temp) {
                cout << st.top().second << " ";
                break;
            }
            st.pop();
        }
        if(!st.size()) cout << 0 << " ";
        st.push({temp, i+1});
    }
}