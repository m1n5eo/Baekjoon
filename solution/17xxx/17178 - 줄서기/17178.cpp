#include <bits/stdc++.h>
using namespace std;

stack<int> st, dg;
int n, sw, cnt, intTemp;
int arr[501], arrSort[501];
char charTemp;

int main() {
    cin >> n; n *= 5;
    for(int i = 0; i < n; i++) {
        cin >> charTemp >> intTemp;
        arr[i] = (charTemp-'A')*1000-intTemp;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(arr[i] > arr[j]) arrSort[i]++;
        }
    }
    for(int i = n-1; i >= 0; i--) st.push(arrSort[i]);
    while(1) {
        if(sw) break;
        else if(st.size() == 0 && dg.size() == 0) break;
        else if(st.size() == 0 && dg.size()) {
            while(1) {
                if(dg.size() == 0) break;
                else if(dg.top() == cnt) {
                    dg.pop();
                    cnt++;
                }
                else if(dg.top() != cnt) {
                    sw = 1;
                    break;
                }
            }
        }
        else if(dg.size() && dg.top() == cnt) {
            dg.pop();
            cnt++;
        }
        else if(st.top() == cnt) {
            st.pop();
            cnt++;
        }
        else {
            dg.push(st.top());
            st.pop();
        }
    }
    if(sw) cout << "BAD";
    else cout << "GOOD";
}