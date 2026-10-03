#include <iostream>
#include <stack>
using namespace std;

#define FASTIO cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
#define lli long long int

int n, a;
lli k, result = 0;
stack<lli> st;

int main() {
    FASTIO

    cin >> n;

    for(int _ = 0; _ < n; _++) {
        cin >> a;

        if(st.size() == 0 || st.top() >= a) st.push(a);
        else if(st.top() < a) {
            result += a-st.top();

            while(st.size() && st.top() < a) {
                st.pop();
            }

            st.push(a);
        }
    }

    result -= st.top();

    while(st.size()) {
        k = st.top();
        st.pop();
    }

    cout << result+k;
}