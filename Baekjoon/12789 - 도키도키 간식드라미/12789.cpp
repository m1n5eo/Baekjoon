#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);

    int n, temp, now = 1;
    stack<int> st;
    queue<int> q;

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> temp;

        q.push(temp);
    }

    while(q.size() || st.size()) {
        if(q.size() && now == q.front()) {
            now += 1;
            q.pop();
        }
        else if(st.size() && now == st.top()) {
            now += 1;
            st.pop();
        }
        else if(st.size() && !q.size() && now != st.top()) {
            break;
        }
        else {
            st.push(q.front());
            q.pop();
        }
    }

    if(q.size() || st.size()) cout << "Sad";
    else cout << "Nice";

    return 0;
}